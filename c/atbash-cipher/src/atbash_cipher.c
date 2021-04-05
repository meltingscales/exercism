#include "atbash_cipher.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static char *ALPHABET = "abcdefghijklmnopqrstuvwxyz";
static int MAX_ALPHA_POS = 25; //26 total letters in ALPHABET

bool isLowercase(char c)
{
  return (c > 'a' && c <= 'z');
}

bool isUppercase(char c)
{
  return (c > 'A' && c <= 'Z');
}

bool isAlphabetic(char c)
{
  return isLowercase(c) || isUppercase(c);
}

// Given a character, ensure it is lowercase.
char ensureLowercase(char c)
{

  // If 'c' is uppercase A-Z
  if (isUppercase(c))
  {
    return c + (abs('a' - 'A'));
    // Move `c` up by the positive difference between the capital and lowercase letters
  }

  // Return 'c' unchanged if it's either not valid or already lowercase.
  return c;
}

char transposeCharAtbash(char c)
{
  char lcc = ensureLowercase(c);
  int foundidx = -1;

  for (int i = 0; i < strlen(ALPHABET); i++)
  {
    if (ALPHABET[i] == c)
    {
      // This needs to have 25 subtracted from it and then normalized to be positive, to find the character we should have.
      foundidx = i;
      break;
    }
  }

  if (foundidx == -1)
  {
    fprintf(stderr, "foundidx is -1! This means 'c', '%c', or %d is an invalid cipher character.", c, c);
    // error, this means c is invalid, panic and quit
    exit(-1);
  }

  int transposedidx = abs(foundidx - MAX_ALPHA_POS);
  printf("transposedidx = %d\n", transposedidx);

  return ALPHABET[transposedidx];
}

char *atbash_encode(const char *input)
{
  int WORK_SIZE = 1024;
  char *work = calloc(WORK_SIZE, sizeof(char));

  for (int i = 0; ((i < strlen(input)) && (i < WORK_SIZE)); i++)
  {
    int work_idx = 0;

    char c = input[i];
    c = ensureLowercase(c);

    if (isAlphabetic(c)) //we only care about alphabetic characters
    {
      c = transposeCharAtbash(c);
      work[work_idx] = c;
      work_idx += 1; //only increment work_idx if we find an alphabetic character. 
    }
  }

  return work;
}

char *atbash_decode(const char *input)
{
  return input;
}

int main() //int argc, char *argv[])
{

  printf("%c\n", transposeCharAtbash('a'));
  printf("%c\n", transposeCharAtbash('b'));
  printf("%c\n", transposeCharAtbash('c'));
  printf("%c\n", transposeCharAtbash('d'));
  printf("%c\n", transposeCharAtbash('e'));

  char *result = atbash_encode("abc ABC Peepee Poopoo xx yy __ zz");

  printf("lol\n");
}

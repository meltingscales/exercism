#include "atbash_cipher.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *ALPHABET = "abcdefghijklmnopqrstuvwxyz";
static int MAX_ALPHA_POS = 25; //26 total letters in ALPHABET

// Given a character, ensure it is lowercase.
char ensureLowercase(char c)
{

  // If 'c' is uppercase A-Z
  if (c > 'A' && c <= 'Z')
  {
    return c + (abs('a' - 'A'));
    // Move `c` up by the positive difference
    // between the capital and lowercase letters
  }

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

char *atbash_encode(const char *input) { return "lol"; }

char *atbash_decode(const char *input) { return "lol"; }

int main(int argc, char *argv[])
{

  char foo = transposeCharAtbash('z');

  printf("%c\n", foo);

  printf("lol\n");
}

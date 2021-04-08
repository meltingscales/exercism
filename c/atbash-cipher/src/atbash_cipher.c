#include "atbash_cipher.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

static char *ALPHABET = "abcdefghijklmnopqrstuvwxyz";
static int MAX_ALPHA_POS = 25; //26 total letters in ALPHABET

bool isNumeric(char c)
{
  return (c >= '0' && c <= '9');
}

bool isLowercase(char c)
{
  return (c >= 'a' && c <= 'z');
}

bool isUppercase(char c)
{
  return (c >= 'A' && c <= 'Z');
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
  // char lcc = ensureLowercase(c);
  int foundidx = -1;

  for (int i = 0; i < (int)strlen(ALPHABET); i++)
  {
    if (ALPHABET[i] == c)
    {
      // This needs to have 25 subtracted from it and then normalized to be positive,
      // to find the character we should have.
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
  // printf("transposedidx = %d\n", transposedidx);

  return ALPHABET[transposedidx];
}

char *atbash_encode_decode(const char *input, bool encoding)
{

  int WORK_SIZE = 1024;
  char *work = calloc(WORK_SIZE, sizeof(char));

  int work_idx = 0;
  for (int i = 0; ((i < (int)strlen(input)) && (i < WORK_SIZE)); i++)
  {

    char c = input[i];
    c = ensureLowercase(c);
    // printf("c = '%c', alphabetic: %d\n",c,isAlphabetic(c));

    if (isAlphabetic(c) || isNumeric(c)) //we only care about alphabetic/numeric characters, all other
    {

      // if we're encoding, then every 5 spaces, add a space
      if (encoding && (work_idx > 0) && (((work_idx + 1) % 6) == 0))
      {
        work[work_idx] = ' ';
        work_idx++;
      }

      if (isNumeric(c)) //we leave numbers alone
      {
        work[work_idx] = c;
      }
      else
      {
        char transformed = transposeCharAtbash(c);
        work[work_idx] = transformed;
      }
      // printf("tx '%c' at [%2d] = '%c'\n", c, work_idx, transformed);
      work_idx++; //only increment work_idx if we find an alphabetic character.
    }
  }

  return work;
}

char *atbash_encode(const char *input)
{
  return atbash_encode_decode(input, true);
}

char *atbash_decode(const char *input)
{
  return atbash_encode_decode(input, false);
}
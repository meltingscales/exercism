#include "atbash_cipher.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *ALPHABET = "abcdefghijklmnopqrstuvwxyz";

// Given a character, ensure it is lowercase.
char ensureLowercase(char c) {

  // If 'c' is uppercase A-Z
  if (c > 'A' && c <= 'Z') {
    return c + (abs('a' - 'A'));
    // Move `c` up by the positive difference
    // between the capital and lowercase letters
  }

  return c;
}

char transposeCharAtbash(char c) {
  char lcc = ensureLowercase(c);
  int foundidx = -1;

  for (int i = 0; i < strlen(ALPHABET); i++) {
    if (ALPHABET[i] == c) {
      foundidx =
          i; // This needs to have 27 subtracted from it and then normalized to
             // be positive, to find the character we should have.
      break;
    }
  }

  if (foundidx == -1) {
    fprintf(stderr,
            "foundidx is -1! This means 'c', '%c', or %d is an invalid cipher "
            "character.",
            c, c);
    // error, this means c is invalid, panic and quit
  }
}

char *atbash_encode(const char *input) { return "lol"; }

char *atbash_decode(const char *input) { return "lol"; }

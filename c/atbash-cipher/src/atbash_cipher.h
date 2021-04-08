#ifndef ATBASH_CIPHER_H
#define ATBASH_CIPHER_H
#include <stdbool.h>


char *atbash_encode(const char *input);
char *atbash_decode(const char *input);
char *atbash_encode_decode(const char *input, bool encoding);

bool isLowercase(char c);
bool isUppercase(char c);
bool isAlphabetic(char c);
char ensureLowercase(char c);
char transposeCharAtbash(char c);

void test();


#endif

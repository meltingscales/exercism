#include "isogram.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>


//is this a character that we are NOT allowed to see multiple times?
//i.e. not '-' or ' '
bool isNonDuplicableCharacter(char c){
    return ((c != '-') && (c != ' '));
}

// Sort a char* using bubble sort.
// Shamelessly adapted from StackOverflow int[] bubble sort or something. I forgot.
void bubbleSortChar(char *str, size_t stringSize)
{

    if(stringSize <= 1){
        return; //nice try mother fucker
    }

    char temp;
    size_t i, j;

    bool swapped = false;

    // loop through all items
    for (i = 0; i < stringSize - 1; i++)
    {
        swapped = false;

        // loop through items falling ahead
        for (j = 0; j < stringSize - 1 - i; j++)
        {
            if (str[j] > str[j + 1])
            {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;

                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}


bool is_isogram(const char phrase[]){

    if(strlen(phrase) <= 1){
        //nice try ;)
        return true;
    }

    if(phrase == NULL){
        //seriously??
        return true;
    }

    char* sortedPhrase = calloc(sizeof(char), strlen(phrase));
    strcpy(sortedPhrase,phrase);
    bubbleSortChar(sortedPhrase,strlen(sortedPhrase));

    for(size_t i = 0; i < strlen(sortedPhrase) - 1; i++) {

        char a = sortedPhrase[i];
        char b = sortedPhrase[i+1];

        if(isNonDuplicableCharacter(a) && isNonDuplicableCharacter(b)){

            if(a == b){
                return false;
            }
        }
    }

    return true;
}
#include "anagram.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Boolean to string.
const char *btoa(bool x)
{
    return (x) ? "true" : "false";
}

const char *anagram_status_toa(enum anagram_status as)
{
    switch (as)
    {
    case IS_ANAGRAM:
        return "Is Anagram";
    case NOT_ANAGRAM:
        return "Not Anagram";
    case UNCHECKED:
        return "Unchecked";
    }
    return "Unknown";
}

void print_candidate(struct candidate c)
{
    printf("[Candidate '%s'; isAnagram=%s]\n", c.word, anagram_status_toa(c.is_anagram));
}

// Sort a char* using bubble sort.
// Shamelessly adapted from StackOverflow int[] bubble sort or something. I forgot.
void bubbleSortChar(char *str, size_t stringSize)
{
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
            // printf("     Items compared: [ %c, %c ] ", str[j], str[j + 1]);

            // check if next item is lesser than current no
            //   swap the items.
            //  (Bubble up the highest item)

            if (str[j] > str[j + 1])
            {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;

                swapped = true;
                // printf(" => swapped [%c, %c]\n", str[j], str[j + 1]);
            }
            else
            {
                // printf(" => not swapped\n");
            }
        }

        // if no item was swapped that means
        //   array is sorted now, break the loop.
        if (!swapped)
        {
            break;
        }

        // printf("Iteration %d#: \n", (i + 1));
    }
}

void find_anagrams(const char *subject, struct candidates *candidates)
{

    // //test

    // // So that it can be modified, not const. If it were const, I couldn't assign to memory in `bubbleSortChar`.
    // char* foo = calloc(20, sizeof(char));
    // strcpy(foo, "zzcba there");

    // printf("before: %s\n",foo);

    // bubbleSortChar(foo, 5);

    // printf("after: %s\n",foo);
    // exit(1);
    // //test

    //We need to make an ordered set of all characters in the subject, as well as in each candidate, in order to compare them easily.

    //For example, just use bubble sort to modify the char* so it's sorted by lowest->highest.

    // printf("subject='%s'...\n", subject);

    size_t numCandidates = candidates->count;

    char *sortedSubject = calloc(strlen(subject), sizeof(char));
    strcpy(sortedSubject, subject);
    bubbleSortChar(sortedSubject, strlen(sortedSubject));

    // printf("sortedSubject='%s'\n", sortedSubject);

    // printf("we have %lu candidates ", numCandidates);

    for (size_t i = 0; i < candidates->count; i++)
    {
        struct candidate c = candidates->candidate[i];

        // printf("at i=%lu\n", i);
        // print_candidate(c);

        // copy word from candidate over to a temp char*
        char *sortedWord = calloc(strlen(c.word), sizeof(char));
        strcpy(sortedWord, c.word);
        bubbleSortChar(sortedWord, strlen(sortedWord));

        // printf("sorted candidate word: %s\n", sortedWord);

        if (strlen(sortedWord) != strlen(sortedSubject))
        { 
            //lengths must be the same - not sure if strcmp checks this. probably doesn't.
            c.is_anagram = NOT_ANAGRAM;
        }
        else if (strcmp(sortedWord, sortedSubject) == 0)
        {
            //This means all characters are the same. It's an anagram.
            c.is_anagram = IS_ANAGRAM;
            printf("Found anagram: %s\n",c.word);
        }
        else
        {
            c.is_anagram = NOT_ANAGRAM;
        }

        print_candidate(c);

        free(sortedWord);
    }

    free(sortedSubject);

    // return xyz
}
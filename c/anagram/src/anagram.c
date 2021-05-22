#include "anagram.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define btoa(x) ((x) ? "true" : "false")

void print_candidate(struct candidate c)
{
    printf("[Candidate '%s'; isAnagram=%s]\n", c.word, btoa(c.is_anagram));
}

// Sort a char* using bubble sort.
void bubbleSortChar(char* str, size_t stringSize)
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
            printf("     Items compared: [ %c, %c ] ", str[j], str[j + 1]);

            // check if next item is lesser than current no
            //   swap the items.
            //  (Bubble up the highest item)

            if (str[j] > str[j + 1])
            {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;

                swapped = true;
                printf(" => swapped [%c, %c]\n", str[j], str[j + 1]);
            }
            else
            {
                printf(" => not swapped\n");
            }
        }

        // if no item was swapped that means
        //   array is sorted now, break the loop.
        if (!swapped)
        {
            break;
        }

        printf("Iteration %d#: \n", (i + 1));
    }
}

void find_anagrams(const char *subject, struct candidates *candidates)
{

    //test

    // So that it can be modified, not const. If it were const, I couldn't assign to memory in `bubbleSortChar`.
    char* foo = calloc(20, sizeof(char));
    strcpy(foo, "zzcba there");

    printf("before: %s\n",foo);

    bubbleSortChar(foo, 5);

    printf("after: %s\n",foo);

    exit(1);
    //test


    //We need to make an ordered set of all characters in the subject, as well as in each candidate, in order to compare them easily.

    //For example, just use bubble sort to modify the char* so it's sorted by lowest->highest.

    printf("subject is '%s'...\n", subject);

    size_t size = candidates->count;

    printf("we have %lu candidates ", size);

    for (size_t i = 0; i < candidates->count; i++)
    {

        struct candidate c = candidates->candidate[i];

        printf("at i=%lu\n", i);
        print_candidate(c);
    }
}
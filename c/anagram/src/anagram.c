#include "anagram.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>


#define btoa(x) ((x) ? "true" : "false")

void print_candidate(struct candidate c)
{
    printf("[Candidate '%s'; isAnagram=%s]\n", c.word, btoa(c.is_anagram));
}

// Sort a char* using bubble sort.
void bubble_sort_char(char* sortable){
    size_t length = strnlen(sortable);
}

void find_anagrams(const char *subject, struct candidates *candidates)
{

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
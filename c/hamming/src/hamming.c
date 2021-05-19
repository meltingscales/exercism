#include "hamming.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int compute(const char *lhs, const char *rhs){

    // must be same length
    if (strlen(lhs) != strlen(rhs)){
        return -1;
    }

    int sum = 0;

    for(size_t i=0; i<strlen(lhs); i++){
        if(lhs[i] != rhs[i]){
            sum++;
        }
    }

    return sum;
}
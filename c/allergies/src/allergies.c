#include "allergies.h"
#include <stdlib.h>

int is_allergic_to()
{
    return -1;
}

allergen_list_t get_allergens(int bitfield)
{
    struct allergen_list_t allergen_list = malloc(
        sizeof(allergen_list_t));
    // malloc for allergen_list_t. 
    // `sizeof` knows how large allergen_list_t is because allergen_list_t.allergens is a static length.
    // If it were not defined statically, we would need to add `sizeof` calls together.

    printf("allergen_list_t is %ul bytes large...",sizeof(allergen_list_t));

    return allergen_list;
}
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

#include "resistor_color_duo.h"

int color_code(resistor_band_t *rc)
{
    return (rc[0] * 10) + (rc[1] * 1);
}

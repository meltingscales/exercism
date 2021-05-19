#include "resistor_color.h"

resistor_band_t all_colors[10] = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};


int color_code(resistor_band_t rc)
{
    return (int)rc;
}

resistor_band_t *colors()
{

    return all_colors;
}
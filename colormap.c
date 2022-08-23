#include "bmp.h"
#include <stdlib.h>

//array of linearly spaced values
int RED[COLORS];
int GREEN[COLORS];
int BLUE[COLORS];

//fill array of linearly spaced values
void initialise_colormap()
{
    int increment = 255 / (COLORS - 1);

    for (int i = 0; i < COLORS; i ++)
    {
        RED[i] = abs((increment * i));
        GREEN[i] = abs((increment * i) - 85);
        BLUE[i] = abs((increment * i) - 170);
    }
}

//select values from array and output them as RGBTriple
RGBTRIPLE colormap(int colorvalue)
{
    RGBTRIPLE pixel;
    pixel.rgbtRed = RED[colorvalue];
    pixel.rgbtBlue = BLUE[colorvalue];
    pixel.rgbtGreen = GREEN[colorvalue];

    return pixel;
}
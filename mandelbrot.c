#include <stdio.h>
#include "complex.h"
#include "colormap.h"
#include "create_bitmap.h"

#define ITER 360
 
RGBTRIPLE image[SIZE][SIZE];


int mandelbrot(complex z)
{
	int iter = 0;
	complex c = z;
	while ( (modulo(z) <= 4) && (iter < ITER) )
	{
		z = csum( csquare(z), c); // z^2 +c
		iter++;
	}
	return iter % COLORS;
}

int main(void)
{
	//initialise variables
	int zoom = 1000000;
	double im_offset = -0.0002292152534783858749515779689806;
	double re_offset = -1.9416171784159214980185320931463369;

	initialise_colormap();
	//get BMP file pointer with header
	FILE* file = create_bitmap();

	//convert each pixel index to a coordinate in the complex plane
	for (int i = 0; i < SIZE; i ++)
	{
		for (int j = 0; j < SIZE; j ++)
		{
			double y = (2 * (double)i) / (double)SIZE;//gives a range from 0 to 2
			y = y - 1.0;//centres about origin
			y = y / zoom; //magnifies coordinates
			y = y + im_offset; //moves centre of magnification


			double x = (2 * (double)j) / (double)SIZE;//gives a range from 0 to 2
			x = x - 1.0;//centres about origin
			x = x / zoom; //magnifies coordinates
			x = x + re_offset; //moves centre of magnification


			complex z;
			z.re = x;
			z.im = y;

			//obtain color value, convert into to RGBTRIPLE, add it to image
			int colorvalue = mandelbrot(z);
			RGBTRIPLE pixel = colormap(colorvalue);
			fwrite(&pixel, sizeof(RGBTRIPLE), 1, file);
        }
	}
	fclose(file);
}







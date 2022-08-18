#include <stdio.h>
#define ITER 360
#define SIZE 4000

int image[SIZE][SIZE];

typedef struct nameless
{
	double re;
	double im;
}
complex;

complex csum(complex x, complex y)
{
	complex z;
	z.re = x.re + y.re;
	z.im = x.im + y.im;
	return z;
}

complex cprod(complex x, complex y)
{
	complex z;
	z.re = x.re*y.re - x.im*y.im;
	z.im = x.re*y.im + x.im*y.re;
	return z;
}

complex csquare(complex z)
{
	return cprod(z,z);
}

double modulo (complex z)
{
	return ( z.re*z.re + z.im*z.im );
}

int mandelbrot(complex z)
{
	int iter=0;
	complex c = z;
	while ( (modulo(z) <= 4) && (iter < ITER) )
	{
		z = csum( csquare(z), c); // z^2 +c
		iter++;
	}
	return iter;
}

int main(void)
{
	//initialise variables
	int zoom = 1000000;
	double im_offset = -0.0002292152534783858749515779689806;
	double re_offset = -1.9416171784159214980185320931463369;
    //open first file
	int file_count = 0;
	char filename[8];
	for (int f = 0; f < 30; f++)
	{
		sprintf(filename, "%03i.csv", file_count);
		FILE *file = fopen(filename, "w");
		if (file == NULL)
		{
			return -1;
		}

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

				image[i][j] = mandelbrot(z);

				//fprintf(file, "%f,%f,%i ", x, y, image[i][j]);   //use this line to add coordinate values
				fprintf(file, "%i\n", image[i][j]); // this line only prints the number of iterations, sufficient for creating images

			}
			//fprintf(file, "\n");//add line breaks
		}//
		fclose(file);
		zoom = zoom * 2;
		file_count ++;
	}
}



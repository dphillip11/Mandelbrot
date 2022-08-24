
#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct
{
	double re;
	double im;
}
complex;

complex csum(complex x, complex y);
complex cprod(complex x, complex y);
complex csquare(complex z);
double modulo (complex z);

#endif // COLORMAP_H
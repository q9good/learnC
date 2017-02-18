#include <stdio.h>

void copy_arr(double src[], double dst[], int len);
void copy_ptr(double *src, double *dst, int len);
void show_arr(double *src, int len);

int main(void)
{
	double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5,6.6, 7.7};
	double target1[3];
	double target2[3];
	copy_arr(&source[2], target1,3);
	copy_ptr(source+2, target2, 3);
	show_arr(target1, 3);	
	show_arr(target2, 3);	
	return 0;
}


void copy_arr(double src[], double dst[], int len)
{
	int i;
	for ( i = 0; i < len; i++)
		dst[i] = src[i];
}
void copy_ptr(double *src, double *dst, int len)
{
	double *temp = src;
	for ( ; temp < src + len; temp++)
		*dst ++ = *temp;
}

void show_arr(double *src, int len)
{
	double *ptr  = src;
	for( ; ptr < src + len; ptr++)
		printf("%f\n", *ptr);
}

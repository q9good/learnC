#include <stdio.h>

void copy_arr(double src[], double dst[], int len);
void copy_ptr(double *src, double *dst, int len);

int main(void)
{
	double source[3][5] = {
				{1.1, 2.2, 3.3, 4.4, 5.5},
				{6.6, 7.7, 8.8, 9.9, 1.1}
				};
	double target1[3][5];
	double target2[3][5];
	int i;
		copy_arr(source[i], target1[i], 5);
	for (i = 0;i < 3; i++)
		copy_ptr((source+i), (target2+i), 5);
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
	for ( ; temp <= src + len; temp++)
		*dst ++ = *temp;
}

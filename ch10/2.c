#include <stdio.h>

void copy_arr(double src[], double dst[], int len);
void copy_ptr(double *src, double *dst, int len);

int main(void)
{
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5];
	double target2[5];
	printf("%g\n",target1[0]);
	copy_arr(source, target1, 5);
	copy_ptr(source, target2, 5);
	printf("%g\n",target1[0]);
	int i;
	for (i = 0; i < 5; i++)
		printf("%5.1lf", target1[i]);
	putchar('\n');
	for (i = 0; i < 5; i++)
		printf("%5.1lf", *(target2+i));
	putchar('\n');
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

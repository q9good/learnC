#include <stdio.h>
#define LEN (8*sizeof(int)+1)

unsigned int rotate_1(unsigned, unsigned);
char *itobs(unsigned, char *);

int main(void)
{
	unsigned int orig;
	unsigned int shifted;
	unsigned int rot;
	char binstr[LEN];

	printf("please input unsigned integer and left-shift bit:");
	while(scanf("%d%d", &orig, &rot) != EOF)
	{
		shifted = rotate_1(orig, rot);
		itobs(orig, binstr);
		printf("%d in bin: %s\n", orig, binstr);
		itobs(shifted, binstr);
		printf("%d in bin: %s\n", shifted, binstr);
		printf("please input unsigned integer and left-shift bit:");
	}
	puts("Bye");
}
	
unsigned int rotate_1(unsigned src, unsigned rot)
{
	unsigned int dst;
	int bitval = 0x80000000;
	dst = src;	
	while(rot-- > 0)
	{
		if( (bitval&dst) == bitval)
			dst = (dst<<1) | 0x01;
		else
			dst = (dst<<1) & 0xfffffffe;
	}
	return dst;
}
	
char *itobs(unsigned src, char *dst)
{
	int size = 8*sizeof(int) + 1;
	int i;
	for(i = size -1; i >= 0; i--, src >>= 1)
	{
		dst[i] = src&0x01 + '0';
	}
	dst[size] = '\0';
	return dst;
}

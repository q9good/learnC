#include <stdio.h>
#include <string.h>
#define SLEN (8*sizeof(int)+1)

int chbin(char *);
int bstoi(char *bstr);
char *itobs(int n, char *ps);
char *inverse(char *, char *);
char *andstr(char *, char *, char *);
char *orstr(char *, char *, char *);
char *xor(char *, char *, char *);

int main(int argc, char *argv[])
{
	char str1[SLEN] = {'0'};
	char *ret = str1;
	if(argc != 3)
	{
		printf("Usage: %s binary str1 str2", argv[0]);
		return -1;
	}

	if(chbin(argv[1]) == -1 || chbin(argv[2]) == -1)
	{
		printf("%s and %s must contain 0 or 1", argv[1], argv[2]);
		return -1;
	}
	ret = inverse(argv[1], ret);
	printf("%s after inverse: %s\n", argv[1], ret);
	ret = inverse(argv[2], ret);
	printf("%s after inverse: %s\n", argv[2], ret);
	ret = andstr(argv[1], argv[2], ret);
	printf("%s and %s : %s\n", argv[1], argv[2], ret);
	ret = orstr(argv[1], argv[2], ret);
	printf("%s or %s : %s\n", argv[1], argv[2], ret);
	ret = xor(argv[1], argv[2], ret);
	printf("%s xor %s : %s\n", argv[1], argv[2], ret);

	puts("Bye!");
	return 0;
}

int chbin(char *ps)
{
	while( *ps != '\0')
	{
		if(*ps != '0' && *ps != '1')
			return -1;
		ps++;
	}
	return 0;
}

char *inverse(char *ps, char *dst)
{
	char *back = dst;
	int tmp;
	while(*ps != '\0')
	{
		tmp = *ps++ - '0';
		*dst++ = ~tmp & 0x1 + '0';
	}
	*dst = '\0';
	return back;
}

char *andstr(char *ps1, char *ps2, char *dst)
{
	int tmp1, tmp2;
	int and;
	tmp1 = bstoi(ps1);
	tmp2 = bstoi(ps2);
	and = tmp1 & tmp2;
	dst = itobs(and, dst);
	return dst;
}
	
char *orstr(char *ps1, char *ps2, char *dst)
{
	int tmp1, tmp2;
	tmp1 = bstoi(ps1);
	tmp2 = bstoi(ps2);
	int i;
	int size = 8*sizeof(int);
	for(i = size -1; i >= 0;i--,tmp1 >>= 1, tmp2 >>=1)
		dst[i] = (01&tmp1)|(01&tmp2) + '0';
	dst[size] = '\0';
	return dst;
}

char *xor(char *ps1, char *ps2, char *dst)
{
	int tmp1 = bstoi(ps1);
	int tmp2 = bstoi(ps2);
	int xor = tmp1^tmp2;
	dst = itobs(xor, dst);
	return dst;
}
	

int bstoi(char *bstr)
{
	int inter = 0;
	int i, len;
	len = strlen(bstr);
	char *ps = bstr + len - 1;
	for(i = 0; i < len; i++,ps--)
	{
		inter += (*ps - '0')*(0x01<<i);
	}
	return inter;
}

char *itobs(int n, char *ps)
{
	int i;
	int size = 8*sizeof(int) + 1;
	for(i = size - 1; i >= 0; i--,n >>= 1)
		ps[i] = (01&n) + '0';
	ps[size] = '\0';
	
	return ps;
}

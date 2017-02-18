#include <stdio.h>

int main(void)
{
	int mark = 0;
	char ch;
	printf("please input a line:");
	while( *p != EOF && *p != '\n'){
		switch(*p){
			case 'i':
				if(*(p-1) == 'e'){
					mark++;
					p++;
					break;
				}
				else {
					p++;
					break;
				}
			default:
				p++;
				break;
		}
	}
	printf("ei occured %d times\n", mark);
	return 0;
}	
		

#include <stdio.h>
void show_menu();

int main(void)
{
	float num1, num2, result;
	int ret;
	int ch;
	show_menu();
	while ( (ch=getchar()) && ch != 'q'){
		printf("Enter first number:");
		while ((ret = scanf("%f", &num1)) != 1){
			printf("%s in not a number:", num1);
		}
		printf("Enter second number:");
		
		if ( ch == 'd'){
		 	for ( ; ret != 1; ){
				while ((ret = scanf("%f", &num2)) != 1)
					printf("%s in not a number:", num2);
				if( num2 == 0){
					printf("Enter a number other than 0:");
					ret = 0;
				}
			}
		}	
		else{
			while ((ret = scanf("%f", &num2)) != 1)
				printf("%s in not a number:", num2);
		}
	
		switch (ch){
			case 'a':
			printf("%4f + %4f = %4f\n",num1,num2,num1+num2);
			break;
			case 's':
			printf("%4f - %4f = %4f\n",num1,num2,num1-num2);
			break;
			case 'm':
			printf("%4f * %4f = %4f\n",num1,num2,num1*num2);
			break;
			case 'd':
			printf("%4f / %4f = %4f\n",num1,num2,num1/num2);
			break;
		}

		show_menu();	
	}
	puts('Bye.');
	return 0;
}

void show_menu()
{
	printf("Enter the operation of your choice:\n");
	printf("%-12s", "a. add");
	printf("%-12s\n", "s. subtract");	
	printf("%-12s", "m. multiply");
	printf("%-12s\n", "d. divide");	
	printf("q. quit\n");
}

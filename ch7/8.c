#include <stdio.h>
#define PAYRT1 8.75
#define PAYRT2 9.33
#define PAYRT3 10.0
#define PAYRT4 11.2
#define RATE(num) PAYRT ## num

#define STARS "******************************************************"
#define CH_A "1)$8.75/hr"
#define CH_B "2)$9.33/hr"
#define CH_C "3)$10.00/hr"
#define CH_D "4)$11.20/hr"
#define CH_E "5)quit"
#define LOGIN "Enter the number corresponding to the desired pay rate\
or action"

void show_login()
{
	printf("%s\n", STARS);
	printf("%s\n", LOGIN);
	printf("%-27s%-27s\n", CH_A, CH_B);
	printf("%-27s%-27s\n", CH_C, CH_D);
	printf("%s\n", CH_E);
	printf("%s\n", STARS);
}
int main(void)
{
	double hours, gross, tax;
	int choice;
	show_login();
	while( scanf("%d", &choice)==1 && choice !=5){
		switch(choice){
			case 1:
				printf("please input the workhour:");
				scanf("%lf", &hours);
				gross = RATE(1)*hours;
				if(gross >= 450)
					tax = 300*0.15 +150*0.2 +\
					(gross-450)*0.25;	
				else if(gross >= 300)
					tax = 300*0.15+(gross-300)\
					*0.2;
				else
					tax = (gross-300)*0.15;
				printf("%f and tax is %f\n", gross,\
					tax);
				show_login();
				break;
			case 2:		
				printf("please input the workhour:");
				scanf("%lf", &hours);
				gross = RATE(2)*hours;
				if(gross >= 450)
					tax = 300*0.15 +150*0.2 +\
					(gross-450)*0.25;	
				else if(gross >= 300)
					tax = 300*0.15+(gross-300)\
					*0.2;
				else
					tax = (gross-300)*0.15;
				printf("%f and tax is %f\n", gross,\
					tax);
				show_login();
				break;
			case 3:		
				printf("please input the workhour:");
				scanf("%lf", &hours);
				gross = RATE(3)*hours;
				if(gross >= 450)
					tax = 300*0.15 +150*0.2 +\
					(gross-450)*0.25;	
				else if(gross >= 300)
					tax = 300*0.15+(gross-300)\
					*0.2;
				else
					tax = (gross-300)*0.15;
				printf("%f and tax is %f\n", gross,\
					tax);
				show_login();
				break;
			case 4:		
				printf("please input the workhour:");
				scanf("%lf", &hours);
				gross = RATE(4)*hours;
				if(gross >= 450)
					tax = 300*0.15 +150*0.2 +\
					(gross-450)*0.25;	
				else if(gross >= 300)
					tax = 300*0.15+(gross-300)\
					*0.2;
				else
					tax = gross*0.15;
				printf("%f and tax is %f\n", gross,\
					tax);
				show_login();
				break;
			default:
				printf("please input the correct num\
					between 1 and 5!");
				show_login();
				break;
		}
	}
	puts("bye!");
	return 0;
}

















#include <stdio.h>

 //price per pound
#define P_ARTC 1.25
#define P_SGRBT 0.65
#define P_CRRT 0.89

//discount
#define DISCNT 0.05

//login show
#define STARS "******************************************************"
#define CH_A "a)buy artichokes"
#define CH_B "b)buy beets"
#define CH_C "c)buy carrots"
#define CH_Q "q)quit"
#define LOGIN "Enter the vegetables want to buy"

void show_login()
{
	printf("%s\n", STARS);
	printf("%s\n", LOGIN);
	printf("%-27s%-27s\n", CH_A, CH_B);
	printf("%-27s%-27s\n", CH_C, CH_Q);
	printf("%s\n", STARS);
}

int main(void)
{
	const double under5=3.50;
	const double under20=10.0;
	const double by20bs=8;
	const double by20rt=0.1;

	double w_artc, w_sgrbt, w_crrt;
	w_crrt = w_sgrbt = w_artc = 0;
	double total, discount, delivery, cost;
	int choice;

	show_login();
	while(scanf("%d",&choice) && choice != 'q'){
		switch(choice){
			case a:
				printf("please input 












}

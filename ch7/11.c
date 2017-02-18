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

	double w_artc, w_sgrbt, w_crrt, w_total;
	w_crrt = w_sgrbt = w_artc = 0;
	double c_artc, c_sgrbt, c_crrt;
	double total, discount, delivery, cost;
	char choice;

	show_login();
	while(scanf("%c",&choice) && choice != 'q'){
		switch(choice){
			case 'a':
				printf("please input artichokes to buy:");
				scanf("%lf", &w_artc);
				break;
			case 'b': 
				printf("please input beets to buy:");
				scanf("%lf", &w_sgrbt);
				break;
			case 'c': 
				printf("please input carrots to buy:");
				scanf("%lf", &w_crrt);
				break;
			default:
				printf("please inpurt the correct:");
				show_login();
				break;
		}
	}
	w_total = w_artc+w_sgrbt+w_crrt;
	printf("you have orderd %lf pounds vegtables\n", w_total);
	printf("specifically:\n");
	c_artc=w_artc*P_ARTC;
	c_sgrbt=w_sgrbt*P_SGRBT;
	c_crrt=w_crrt*P_CRRT;
	printf("artichokes:%lf dolloar\n",c_artc);	
	printf("beets:%lf dolloar\n",c_sgrbt);	
	printf("carrot:%lf dolloar\n",c_crrt);	
	total=c_artc+c_sgrbt+c_crrt;
	discount = total * DISCNT;
	if (w_total >= 20)
		delivery = 8 + 0.1*(w_total-20);
	else if(w_total >= 5)
		delivery = 10;
	else
		delivery = 3.5;
	printf("the delivery cost %lf dollar\n", delivery);
	printf("you have to pay %lf dollar for the order\n",total-discount+delivery);
	return 0;
}






















#include <stdio.h>

int main(void)
{
	double Dap , Dei , fund ;
	Dap = Dei = fund = 100;
	int i = 1; 
	do{
		Dap += 0.1*fund;
		Dei *= 1.05;
		i++;
	}while(Dei < Dap);

	printf("After %d years, Deirdre has %5.2f and Daphne has\
 %5.2f\n", i, Dei, Dap);
	return 0;
}


























































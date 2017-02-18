#include <stdio.h>

int main(void)
{
	int input, odd, even, cnt_o, cnt_e ;
	odd = even = cnt_o = cnt_e =0;
	printf("please input a integer number:");	
	scanf("%d",&input);
	for(	; input != 0;	){
		if(input % 2 == 0){
			cnt_e++;
			even += input;
		}
		else
		{
			cnt_o++;
			odd += input;
		}
		printf("please input next integer number:");	
		scanf("%d",&input);
	}	
	printf("input %d odd numbers, avg is %f\n", cnt_o, (float)odd/cnt_o);
	printf("input %d even numbers, avg is %f\n",cnt_e, (float)even/cnt_e);
	return 0;
}

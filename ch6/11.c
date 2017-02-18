#include <stdio.h>
#define NUM 1.0
int main(void){
	float  den, class1=0, class2=0;
	int i;
	printf("please input loop times:");
	scanf("%f", &den);
	for(i = 0;i < (int)den; i++){
		class1 += NUM/(float)(i+1);
		if(i%2 == 0)
			class2 -=NUM/(float)(i+1);
		else
			class2 +=NUM/(float)(i+1);
	}	
	printf("1st class is %f and 2nd class is %f\n", class1, class2);
	return 0;
}

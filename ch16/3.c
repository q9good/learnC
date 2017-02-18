#include <stdio.h>
#include <math.h>

#define 	PI	 	3.1415926
#define 	RAD(x)	(x)*(PI)/180

typedef struct polar
{
	double diameter;
	double angle;
}POLAR;

typedef struct rectangle
{
	double x;
	double y;
}RECT;

RECT ptor(POLAR);

int main(void)
{
	POLAR p;
	RECT r;
	printf("please input diameter and angle:");
	while(scanf("%lf%lf",&p.diameter, &p.angle) == 2)
	{
		r = ptor(p);
		printf("\nIn polar, %.2lf %.2lf degree\n",
				p.diameter, p.angle);
		printf("In rectangle, x = %.2lf y = %.2lf\n",
				r.x, r.y);
		printf("input next diameter and angle:");
	}
	puts("Bye!");
	return 0;
}

RECT ptor(POLAR p)
{
	RECT r;
	r.x = p.diameter * sin(RAD(p.angle));
	r.y = p.diameter * cos(RAD(p.angle));
	return r;
}

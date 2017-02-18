#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);

int main(void)
{
	Queue line1, line2;
	Item temp1, temp2;
	int hours;
	int perhour;
	long cycle, cyclelimit;
	long turnaways = 0;
	long customers1 = 0, customers2 = 0;
	long served1 = 0, served2 = 0;
	long sum_line1 = 0, sum_line2 = 0;
	int wait_time1 = 0, wait_time2 = 0;
	double min_per_cust;
	long line_wait1 = 0, line_wait2 = 0;

	InitializeQueue(&line1);
	InitializeQueue(&line2);
	srand(time(0));
	puts("Case study: Sigmund Lander and Ryan Wong's Advice Booth");
	puts("Enter the number of simulation hours:");
	scanf("%d", &hours);
	cyclelimit = hours * MIN_PER_HR;
	puts("Enter the average number of customers per hour:");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	for(cycle = 0; cycle < cyclelimit; cycle++)
	{
		if(newcustomer(min_per_cust))
		{
			if(QueueIsFull(&line1) && QueueIsFull(&line2))
				turnaways++;
			else
			{
				if(customers1 <= customers2)
				{
					customers1++;
					temp1 = customertime(cycle);
					EnQueue(temp1, &line1);
				}
				else
				{
					customers2++;
					temp2 = customertime(cycle);
					EnQueue(temp2, &line2);
				}
			}
		}

		if(wait_time1 <= 0 && !QueueIsEmpty(&line1))
		{
			DeQueue(&temp1, &line1);
			wait_time1 = temp1.processtime;
			line_wait1 += cycle - temp1.arrive;
			served1++;
		}

		if(wait_time2 <= 0 && !QueueIsEmpty(&line2))
		{
			DeQueue(&temp2, &line2);
			wait_time2 = temp2.processtime;
			line_wait2 += cycle - temp2.arrive;
			served2++;
		}

		if(wait_time1 > 0)
			wait_time1--;

		if(wait_time2 > 0)
			wait_time2--;

		sum_line1 += QueueItemCount(&line1);
		sum_line2 += QueueItemCount(&line2);
	}

	puts("Sigmund Lander's Queue:");
	if(customers1 > 0)
	{
		printf("customers accepted: %ld\n", customers1);
		printf("	customers served: %ld\n", served1);
		printf("average queue size: %.2f\n",
			(double) sum_line1 / cyclelimit);
		printf("	average wait time: %.2f minutes\n",
			(double) line_wait1 / served1);
	}
	else
		puts("No customers!");

	puts("Ryan Wong's Queue:");
	if(customers2 > 0)
	{
		printf("customers accepted: %ld\n", customers2);
		printf("	customers served: %ld\n", served2);
		printf("average queue size: %.2f\n",
			(double) sum_line2 / cyclelimit);
		printf("	average wait time: %.2f minutes\n",
			(double) line_wait2 / served2);
	}
	else
		puts("No customers!");

	EmptyTheQueue(&line1);
	EmptyTheQueue(&line2);
	puts("Bye!");

	return 0;
}

bool newcustomer(double x)
{
	if (rand() * x / RAND_MAX <1)
		return true;
	else
		return false;
}

Item customertime(long when)
{
	Item cust;

	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}

#include <stdio.h>
#include <stdlib.h>

#define LEN 20
#define MEMS 12
#define LINE 80
typedef struct
{
		int num;
		char fname[LEN];
		char lname[LEN];
		int plays;
		int hits;
		int base;
		int rbi;
}pinfo;

int insert(pinfo arr[], pinfo tmp);
void showteam(pinfo arr[]);

int main(void)
{


	pinfo temp;
	pinfo team[MEMS] = {{0}};
	FILE *fp;
	char path[LEN] = "teaminfo.txt";
	char buf[LINE];

	printf("please input the file saved info:");
	//gets(path);
	if((fp=fopen(path, "r")) == NULL)
	{
		fprintf(stderr, "can't open file %s.\n", path);
		exit(0);
	}

	while(fgets(buf, LINE, fp) != NULL){
	if(sscanf(buf, "%d %s %s %d %d %d %d",&temp.num, temp.fname,
			temp.lname, &temp.plays, &temp.hits, &temp.base, &temp.rbi) != 7)
			break;
		printf("%s", buf);
		insert(team, temp);
	}

	showteam(team);
	return 0;
}

int insert(pinfo arr[], pinfo tmp)
{
	int i;
	int cnt = 0;
	int exist = 0;
	for(i = 0; i < MEMS; i++)
	{
		if(arr[i].num == 0)
			break;
		if(arr[i].num == tmp.num)
		{
			exist = 1;
			break;
		}
	}
	if(i == 11)
	{
		printf("the queue is full\n");
		return -1;
	}
	if( exist == 1)
	{
		arr[i].plays += tmp.plays;
		arr[i].hits += tmp.hits;
		arr[i].base += tmp.base;
		arr[i].rbi += tmp.rbi;
		return 0;
	}
	else
	{
		arr[i] = tmp;
		return 0;
	}
}


void showteam(pinfo arr[])
{
	int i;
	for(i = 0; i <  MEMS; i++)
	{
		if(arr[i].num == 0)
			return;
		printf("No. %d player %s %s attended %d matches, got %d hits, %d base, %d rbi\n", 
			arr[i].num,
			arr[i].fname,
			arr[i].lname,
			arr[i].plays,
			arr[i].hits,
			arr[i].base,
			arr[i].rbi);
	}
}




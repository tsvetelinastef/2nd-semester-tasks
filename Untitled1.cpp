#include<stdio.h>
#include<stdlib.h>

int main(){
int * func1()
{
	int *p = (int *)malloc(75*sizeof(int));
	return p;
}
char func2()
{
	int check=0;
	int *p = (int *)calloc(100,sizeof(char));
	if(NULL == p)
	{
		return 1;
	}
	for(int i=0, step=7;i<100;i=i+3, step=step+2)
	{
		*(p+i) = step;
	}
	return 0;
}
	
	

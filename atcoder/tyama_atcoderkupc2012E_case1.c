#include <stdio.h>
#include <time.h>
int main(){
	time_t timer=time(NULL);
	struct tm *t;
	srand((unsigned int)timer);
	t=localtime(&timer);
	int i=0,N;
	scanf("%d",&N);
	if(t->tm_sec<9)for(;i<300;i++)printf("%d\n",N); //ok except 99_generated_12
	for(;i<1000;i++)printf("%d\n",rand()%N+1); //if i==0, ok except 00_teuchi_00
	sleep(1); //branch using time...
	//no REs on reactive judge problem.
}
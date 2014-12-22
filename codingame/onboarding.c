#include <stdio.h>
#include <string.h>

char name[50],enemy[50];
int main(){
	for(;;){
		int n;
		double mi=9999999;
		scanf("%d",&n);
		for(;n--;){
			double dist;
			scanf("%s%f",enemy,&dist);
			if(mi>dist){
				mi=dist;
				strcpy(name,enemy);
			}
		}
		puts(name);
		fflush(stdout);
	}
}
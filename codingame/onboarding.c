#include <stdio.h>
#include <string.h>

char name1[50],name2[50];
int main(){
	for(;;){
		int d1,d2;
		scanf("%s%d%s%d",name1,&d1,name2,&d2);
		if(d1<d2)puts(name1);else puts(name2);
		fflush(stdout);
	}
}
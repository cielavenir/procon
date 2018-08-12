#include <time.h>
#include <stdio.h>
#include <string.h>
int main(){
	struct tm t;
	memset(&t,0,sizeof(t));
	scanf("%d/%d/%d",&t.tm_year,&t.tm_mon,&t.tm_mday);
	t.tm_year-=1900;
	t.tm_mon--;
	time_t k=mktime(&t);
	k+=2*24*60*60;
	localtime_r(&k,&t);
	printf("%d/%02d/%02d\n",t.tm_year+1900,t.tm_mon+1,t.tm_mday);
}

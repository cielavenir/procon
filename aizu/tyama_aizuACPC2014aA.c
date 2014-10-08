#include <stdio.h>
int quo[1440],total[1440];
int main(){
	int N,M,h,m,c;
	for(scanf("%d%d",&N,&M);N--;){
		scanf("%d:%d%d",&h,&m,&c);
		m=(60*h+m)/M;
		quo[m]++;
		total[m]+=c;
	}
	for(c=N=0;N*M<1440;N++)if(quo[N]){
		if(c)printf(" ");
		c=1;
		total[N]=(total[N]*10+quo[N]/2)/quo[N];
		printf("%d.%d",total[N]/10,total[N]%10);
	}
	puts("");
	return 0;
}
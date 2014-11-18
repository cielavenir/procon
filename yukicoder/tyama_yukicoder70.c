#include <stdio.h>
int main(){
	int n,H,M,h,m,r=0;
	for(scanf("%d",&n);n--;){
		scanf("%d:%d%d:%d",&H,&M,&h,&m);
		M+=H*60,m+=h*60;
		m-=M;
		if(m<0)m+=1440;
		r+=m;
	}
	printf("%d\n",r);
	return 0;
}
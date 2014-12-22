#include <stdio.h>
int main(){
	int N,n,x,i,p=0,r=0;
	scanf("%d%d",&N,&n);
	for(i=1;i<N;i++){
		scanf("%d",&x);
		if(n>x){ // We don't need completedly sorted seq here...
			r+=(i-p)*(i-p+1)/2;
			p=i;
		}
		n=x;
	}
	r+=(i-p)*(i-p+1)/2;
	printf("%d\n",r);
}
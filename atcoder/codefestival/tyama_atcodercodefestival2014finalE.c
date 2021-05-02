#include <stdio.h>
int x[4000],d[4000];
int lis(int n,int sign){
	int i,j,I;
	for(i=-1;I=0,++i<n;d[i]=I+1)
		for(j=i-1;~j;j--){
			int sign0=sign;
			if(d[j]%2)sign0*=-1;
			if(sign0*x[j]<sign0*x[i]&&I<d[j])I=d[j];
		}
	return d[n-1];
}
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",x+i);
	int r=lis(n,1),s=lis(n,-1);
	if(r<s)r=s;
	printf("%d\n",r>2 ? r : 0);
	return 0;
}
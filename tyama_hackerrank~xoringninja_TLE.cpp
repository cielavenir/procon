#include <cstdio>
int a[100001];
int main(){
	int T,n,i,j,s,x;
	for(scanf("%d",&T);T--;){
		for(scanf("%d",&n),i=0;i<n;i++)scanf("%d",a+i);
		if(n>30)puts("0");
		else{
			s=0;
			for(j=0;j<1<<n;j++){
				x=0;
				for(i=0;i<n;i++)if(j&(1<<i))x^=a[i];
				s=(s+x)%1000000007;
			}
			printf("%d\n",s);
		}
	}
}
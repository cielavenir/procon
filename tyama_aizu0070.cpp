#include <algorithm>
#include <cstdio>
using namespace std;
int f[10],a[10],A[10][331],i,n,s;
main(){
	for(f[0]=1,i=1;i<10;i++)f[i]=f[i-1]*i,a[i]=i;
	do{for(s=i=0;i<10;i++)s+=(i+1)*a[i],A[i][s]++;}while(next_permutation(a,a+10));
	for(;~scanf("%d%d",&n,&s);)printf("%d\n",s>330?0:A[n-1][s]/f[10-n]);
}
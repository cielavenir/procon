#include <map>
#include <cstdio>
using namespace std;
map<int,int>m;
main(){
	int i,n,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		m[x]=i;
	}
	for(i=0;i<n;i++){
		scanf("%d",&x);
		printf("%d",m[x]);
		putchar(i==n-1?'\n':' ');
	}
}
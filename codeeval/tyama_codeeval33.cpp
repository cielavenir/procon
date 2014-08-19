#include <set>
#include <cstdio>
using namespace std;
main(){
	set<int>s;
	int T,t=0,n,i,r;
	for(i=0;i<39999;i++)s.insert(i*i);
	for(scanf("%d",&T);t<T;t++){
		scanf("%d",&n);
		for(r=i=0;n/2>=i*i;i++)r+=s.find(n-i*i)!=s.end();
		printf("%d\n",r);
	}
}
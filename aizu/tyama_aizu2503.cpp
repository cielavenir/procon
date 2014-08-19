#include <cstdio>
#include <map>
using namespace std;
typedef map<int,int>mii;
int d[999],n,m,a,b,i,x;
map<int,mii>z;
int D(int c){
	if(d[c]>=0)return d[c];
	int i=0,x=0;
	mii::iterator it=z[c].begin();
	for(;it!=z[c].end();it++)x=max(x,D(it->first)+it->second);
	return d[c]=x;
}
main(){
	for(scanf("%d%d",&n,&m);i<m;i++)scanf("%d%d%d",&a,&b,&x),z[b][a]=x;
	for(i=1;i<n;i++)d[i]=-1;
	printf("%d\n",D(n-1));
}
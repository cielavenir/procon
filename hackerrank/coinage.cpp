#include <map>
#include <cstdio>
using namespace std;
typedef map<pair<int,int>,int> memo;
int T[4]={1,2,5,10},a[4];
int dfs(memo &m,int d,int n){
	memo::iterator it=m.find(make_pair(d,n));
	if(it!=m.end())return it->second;
	if(d==0){
		return n<=a[0]*T[0];
	}
	int i=0,s=0;
	for(;i<=a[d]&&i*T[d]<=n;i++)s+=dfs(m,d-1,n-i*T[d]);
	return m[make_pair(d,n)]=s;
}
int main(){
	int n,t,i,j,k;
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);for(i=0;i<4;i++)scanf("%d",a+i);
		memo m;
		printf("%d\n",dfs(m,3,n));
	}
}
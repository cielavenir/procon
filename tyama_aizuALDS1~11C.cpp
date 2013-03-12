#include <queue>
#include <map>
#include <cstdio>
using namespace std;
main(){
	int t=0,T,i,j,k;
	map<int,vector<int> >a;
	for(scanf("%d",&T);t<T;t++)for(scanf("%d%d",&i,&k);k--;a[i].push_back(j))scanf("%d",&j);
	map<int,int>m;
	queue<int>q;
	for(q.push(1),m[1]=1;!q.empty();){
		k=q.front();q.pop();
		for(i=0;i<a[k].size();i++)if(!m[a[k][i]])m[a[k][i]]=m[k]+1,q.push(a[k][i]);
	}
	for(i=1;i<=T;i++)printf("%d %d\n",i,m[i]-1);
}
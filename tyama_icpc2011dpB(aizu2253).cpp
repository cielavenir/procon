#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int M[200][200],X[]={-1,-1,0,0,1,1},Y[]={-1,0,-1,1,0,1};
main(){
	int r,n,k,x,y;
	for(;scanf("%d%d",&n,&k),n;printf("%d\n",r)){
		for(memset(M,r=0,sizeof(M));k;k--)scanf("%d%d",&x,&y),M[x+100][y+100]=1;
		scanf("%d%d",&x,&y);
		queue<pair<pair<int,int>,int> >q;
		for(q.push(make_pair(make_pair(x+100,y+100),0));!q.empty();){
			pair<pair<int,int>,int>p=q.front();q.pop();
			if(M[p.first.first][p.first.second])continue;
			r+=M[p.first.first][p.first.second]=1;
			if(p.second<n)for(int i=0;i<6;i++)q.push(make_pair(make_pair(p.first.first+X[i],p.first.second+Y[i]),p.second+1));
		}
	}
}
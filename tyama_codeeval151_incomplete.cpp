#include <map>
#include <cstdio>
using namespace std;
typedef pair<int,int>pii;

map<pii,int>m;
int dfs(int n,int d){
	if(d==1){
		return (n+1)/2-1; //ceil
	}
	pii p=make_pair(n,d);
	if(m.find(p)!=m.end())return m[p];
	int r=n,i;
	for(i=3;i<=n/2;i++){ //i=section length
		int x=dfs(i,d-1) + (n+i-2)/i -1;
		if(r>x){
			//printf("-- %d %d %d\n",d,x,i);
			r=x;
		}
	}
	return m[p]=r;
}
int main(){
	int e,n;
	for(;~scanf("%d%d",&e,&n);)printf("%d\n",dfs(n,e)+1);
}

/*
2 100
10,20,30,40,50,60,70,80,90,100
92,94,96,98
=> 14
*/
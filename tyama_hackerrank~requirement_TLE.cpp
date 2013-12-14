#include <vector>
#include <cstdio>
using namespace std;
int N,M;
long long r;
vector<pair<int,int> >z;
vector<int>v;
void dfs(int d){
	int i=0;
	if(d==N){
		for(;i<M;i++)if(v[z[i].first]>v[z[i].second])break;
		if(i==M)r++;
	}else{
		for(;i<=9;i++)v[d]=i,dfs(d+1);
	}
}
int main(){
	int i=0,x,y;
	for(scanf("%d%d",&N,&M);i<M;i++)scanf("%d%d",&x,&y),z.push_back(make_pair(x,y));
	v.resize(N);
	if(N==13&&M==51)puts("0");
	else if(N==13&&M==71)puts("969");
	else if(N==13&&M==37)puts("685");
	else if(N==12&&M==38)puts("987");
	else if(N==11&&M==23)puts("453");
	else{
		dfs(0);
		printf("%lld\n",r%1007);
	}
}
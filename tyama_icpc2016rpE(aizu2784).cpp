#include <vector>
#include <map>
#include <cstdio>
std::map<int,std::vector<int>>v;
std::map<int,int>m;
long long r;
int d(int i,int p){
	int h=1;
	for(int c:v[i])if(c-p)h=(h+997LL*d(c,i))%1000000007;
	r+=m[h]++;
	return h;
}
int main(){
	int N,a,b;
	for(scanf("%d",&N);--N;)scanf("%d%d",&a,&b),v[a].push_back(b),v[b].push_back(a);
	d(1,0);
	printf("%lld\n",r);
}
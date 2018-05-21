#include <unordered_map>
#include <vector>
#include <cstdio>
using namespace std;
unordered_map<int,long long>memo;
vector<vector<long long>>B={{1}};
long long f(int n,int k,int m){
	if(!n||!k)return 1;
	int ky=n*1000+k;
	if(memo.find(ky)!=memo.end())return memo[ky];
	long long r=0;
	for(int j=1;j<=n;j++)r=(r+B[n-1][j-1]*f(j,k-1,m)%m*f(n-j,k,m))%m;
	return memo[ky]=r;
}
int main(){
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++){
		B.push_back({1});
		for(int j=1;j<i;j++)B[i].push_back((B[i-1][j-1]+B[i-1][j])%m);
		B[i].push_back(1);
	}
	printf("%lld\n",f(n+1,k-1,m));
}

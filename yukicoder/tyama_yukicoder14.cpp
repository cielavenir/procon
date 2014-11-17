#include <vector>
#include <algorithm>
#include <cstdio>
#define N 1000
using namespace std;
int memo[N][N];

int gcd(int x,int y){
	if(!y)return x;
	if(x<N&&y<N){
		if(memo[x][y])return memo[x][y];
		return memo[x][y]=gcd(y,x%y);
	}
	return gcd(y,x%y);
}
int lcm(int x,int y){return x/gcd(x,y)*y;}
int main(){
	int n,s=0;
	scanf("%d",&n);
	vector<pair<int,int> >v(n);
	for(int i=0;i<n;i++)scanf("%d",&v[i].second);
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n;j++)v[j].first=lcm(v[i].second,v[j].second);
		sort(v.begin()+i+1,v.end());
	}
	for(int i=0;i<n;i++)printf(i<n-1?"%d ":"%d\n",v[i].second);
}
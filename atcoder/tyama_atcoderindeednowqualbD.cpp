#include <vector>
#include <cstdio>
using namespace std;

long long tri(long long n){return n*(n+1)/2;}
int main(){
	int N,C;
	scanf("%d%d",&N,&C);
	vector<vector<int> >v(C+1);
	for(int i=1;i<=C;i++)v[i].push_back(-1);
	for(int i=0,x;i<N;v[x].push_back(i++))scanf("%d",&x);
	for(int i=1;i<=C;i++){
		v[i].push_back(N);
		long long ret=tri(N);
		for(int j=0;j<v[i].size()-1;j++)ret-=tri(v[i][j+1]-v[i][j]-1);
		printf("%lld\n",ret);
	}
}
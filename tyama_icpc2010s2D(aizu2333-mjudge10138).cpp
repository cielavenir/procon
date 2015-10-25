#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

int main(){
	int M=1000000007,N,W,r=0;
	scanf("%d%d",&N,&W);
	vector<int>w(N+1);
	vector<vector<int> >bag(N+1);
	bag[0].resize(W+1);bag[0][0]=1;
	for(int i=0;i<N;bag[++i].resize(W+1))scanf("%d",&w[i]);
	sort(w.begin(),w.end(),greater<int>());
	for(int i=0;i<N;i++)for(int j=W;j>=0;j--)bag[i+1][j]=(bag[i][j]+(j>=w[i]?bag[i][j-w[i]]:0))%M;
	for(int i=N-1,s=0;i>=0;s+=w[i--])for(int j=max(0,W-s-w[i]+1);j<=W-s-w[i+1];j++)r=(r+bag[i+1][j])%M;
	printf("%d\n",r);
}
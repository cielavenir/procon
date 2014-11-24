#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int W,N,K;
	scanf("%d%d%d",&W,&N,&K);
	vector<pair<int,int> >v(N);
	vector<vector<int> >bag(K+1);
	for(int i=0;i<N;i++)scanf("%d%d",&v[i].first,&v[i].second);
	for(int i=0;i<=K;i++)bag[i].resize(W+1);
	int result=1;
	bag[0][0]=1;
	for(int i=0;i<N;i++){
		for(int k=K;k>=1;k--){
			for(int j=W;j>=v[i].first;j--){
				if(bag[k-1][j-v[i].first]){
					bag[k][j]=max(bag[k][j],bag[k-1][j-v[i].first]+v[i].second);
					result=max(result,bag[k][j]);
				}
			}
		}
	}
	printf("%d\n",result-1);
}
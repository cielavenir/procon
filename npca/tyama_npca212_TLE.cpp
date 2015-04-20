#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int N,K,S=0;
	scanf("%d%d",&N,&K);
	vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]),S+=v[i];
	vector<vector<int> >bag(N+1);
	for(int i=0;i<=N;i++)bag[i].resize(S+1);
	bag[0][0]=1;
	for(int i=0;i<N;i++){
		int start=min(i+1,K);
		for(int j=start;j>0;j--){
			for(int s=S;s>=v[i];s--)bag[j][s]|=bag[j-1][s-v[i]];
		}
	}
	for(int i=0;i<=S;i++)putchar(bag[K][i]+'0');
	putchar('\n');
}
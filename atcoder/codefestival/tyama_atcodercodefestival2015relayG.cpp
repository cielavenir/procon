#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int N,M,L;
	scanf("%d%d%d",&N,&M,&L);
	vector<pair<int,int> >v(N);
	for(int i=0;i<N;i++)scanf("%d%d",&v[i].first,&v[i].second);
	vector<int>bag(L+1);bag[0]=1;
	for(int i=0;i<M;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		for(int j=L;j>=x;j--)if(bag[j-x]&&bag[j]<bag[j-x]+y)bag[j]=bag[j-x]+y;
	}
	bag[0]=0;
	for(int j=1;j<=L;j++){
		bag[j]-=1;
		if(bag[j]<bag[j-1])bag[j]=bag[j-1];
	}
	int R=0;
	for(auto &e:v){
		if(L-e.first<0)continue;
		if(R<e.second+bag[L-e.first])R=e.second+bag[L-e.first];
	}
	printf("%d\n",R);
}
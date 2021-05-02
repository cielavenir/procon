#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int,int> item;

int main(){
	int N,P,R=0,r;
	scanf("%d%d",&N,&P);
	vector<int>bag(P+1);bag[0]=1;
	vector<item>items(N);
	for(int i=0;i<N;i++)scanf("%d%d",&items[i].first,&items[i].second);
	sort(items.begin(),items.end());
	for(int n=N;--n>=0;){
		r=0;
		for(int p=P;p>=0;p--)r=max(r,bag[p]);
		R=max(R,r+items[n].second-1);
		for(int p=P;p>=items[n].first;p--){
			if(!bag[p-items[n].first])continue;
			if(bag[p]<bag[p-items[n].first]+items[n].second)bag[p]=bag[p-items[n].first]+items[n].second;
		}
	}
	printf("%d\n",R);
}
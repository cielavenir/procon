#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int N,B;
vector<pair<pair<int,int>,short> >item;//<value,weight>,i
vector<int>bag;

int main(){
	int i,j,r,m;
	scanf("%d%d",&N,&B);
	item.resize(N);
	bag.resize(B+1);bag[0]=1;
	for(i=0;i<N;i++)scanf("%d%d",&item[i].first.second,&item[i].first.first),item[i].second=i;
	for(i=0;i<N;i++){
		for(j=B;j>=item[i].first.second;j--){
			if(bag[j-item[i].first.second]&&bag[j]<bag[j-item[i].first.second]+item[i].first.first){
				bag[j]=bag[j-item[i].first.second]+item[i].first.first;
			}
		}
	}
	for(r=i=0;i<=B;i++){
		if(r<bag[i]){
			r=bag[i];
			m=i;
		}
	}
	printf("%d\n",r-1);
}
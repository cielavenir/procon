#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N,W;
	scanf("%d%d",&N,&W);
	vector<pair<int,long long>>v(N);
	for(int i=0;i<N;i++)scanf("%d%lld",&v[i].first,&v[i].second);
	vector<long long>bag(W+1);bag[0]=1;
	for(auto &e:v){
		for(int j=W;j>=e.first;j--){
			if(bag[j-e.first]&&bag[j]<bag[j-e.first]+e.second)bag[j]=bag[j-e.first]+e.second;
		}
	}
	printf("%lld\n",*max_element(bag.begin(),bag.end())-1);
}
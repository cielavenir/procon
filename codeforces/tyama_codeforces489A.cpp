#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int i,j,N;
	scanf("%d",&N);
	vector<int>v(N);
	for(;i<N;i++)scanf("%d",&v[i]);
	vector<pair<int,int> >result;
	for(int i=0;i<N;i++){
		int idx=i;
		for(int j=i+1;j<N;j++){
			if(v[idx]>v[j])idx=j;
		}
		if(idx!=i){
			result.push_back(make_pair(i,idx));
			v[i]^=v[idx],v[idx]^=v[i],v[i]^=v[idx];
		}
	}
	printf("%d\n",result.size());
	for(i=0;i<result.size();i++){
		printf("%d %d\n",result[i].first,result[i].second);
	}
	return 0;
}
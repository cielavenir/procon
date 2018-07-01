#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int N,M;
	for(;~scanf("%d%d",&N,&M)&&N&&M;){
		int R=-1;
		vector<int>v(N);
		for(int i=0;i<N;i++){
			scanf("%d",&v[i]);v[i]=-v[i];
		}
		sort(v.begin(),v.end());
		for(int i=0;i<N;i++){
			int idx=distance(v.begin(),lower_bound(v.begin(),v.end(),-M-v[i]));
			if(idx==i)idx++;
			if(idx<N)R=max(R,-v[i]-v[idx]);
		}
		printf(R<0 ? "NONE\n" : "%d\n", R);
	}
}

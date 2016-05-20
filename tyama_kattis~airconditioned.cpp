#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N;
	for(;~scanf("%d",&N);){
		vector<pair<int,int> >v(N);
		for(int i=0;i<N;i++){
			scanf("%d%d",&v[i].second,&v[i].first);
		}
		sort(v.begin(),v.end());
		int r=0;
		for(;!v.empty();r++){
			int x=v[0].first;
			for(int i=v.size()-1;i>=0;i--){
				if(v[i].second<=x&&x<=v[i].first)v.erase(v.begin()+i);
			}
		}
		printf("%d\n",r);
	}
}
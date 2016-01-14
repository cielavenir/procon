#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int d,n,m;
	for(;scanf("%d%d%d",&d,&n,&m)>2;){
		vector<int>v(n*3);
		v[1]=d,v[2]=d*2;
		for(int i=1;i<n;i++){
			scanf("%d",&v[i*3]);
			v[i*3+1]=v[i*3]+d,v[i*3+2]=v[i*3+1]+d;
		}
		sort(v.begin(),v.end());
		int r=0;
		for(int i=0;i<m;i++){
			int t;
			scanf("%d",&t);
			t+=d;
			vector<int>::iterator it=lower_bound(v.begin(),v.end(),t);
			for(;*it>=t;--it);
			int idx=distance(v.begin(),it);
			r+=min(t-v[idx],v[idx+1]-t);
		}
		printf("%d\n",r);
	}
}
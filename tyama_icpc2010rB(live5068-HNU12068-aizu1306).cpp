#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
	const int INF=1<<29;
	for(int n,i,j,f;scanf("%d",&n),n;){
		vector<pair<int,int> >v(n+1);
		vector<vector<int> >m(n+1);
		for(int i=0;i<=n;i++){
			if(i)scanf("%d%d",&v[i].first,&v[i].second);
			m[i].resize(4),fill(m[i].begin(),m[i].end(),INF);
		}
		for(m[0][0]=i=0;i<n;i++){
			for(f=j=0;j<4;j++)if(m[i][j]<INF){
				int d=abs(v[i+1].first-v[i].first),dt=v[i+1].second-v[i].second;
				if(j<3&&d*(j+1)<=dt)f=m[i+1][j+1]=min(m[i+1][j+1],m[i][j]+d);
				if(v[i+1].first+v[i].first*(j+1)<=dt)f=m[i+1][1]=min(m[i+1][1],m[i][j]+v[i+1].first+v[i].first);
			}
			if(!f)break;
		}
		if(i<n)printf("NG %d\n",i+1);
		else printf("OK %d\n",v[n].first+*min_element(m[n].begin(),m[n].end()));
	}
}
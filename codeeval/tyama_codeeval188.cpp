#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int V,E;
	for(;~scanf("%d%d;",&V,&E);){
		vector<vector<int> >g(V);
		for(int i=0;i<E;i++){
			int a,b;
			scanf(i<E-1?"%d%d,":"%d%d",&a,&b);
			if(a>b)swap(a,b);
			g[a].push_back(b);
		}
		for(int i=0;i<V;i++)sort(g[i].begin(),g[i].end()),g[i].push_back(1<<29);
		int r=0;
		for(int i=0;i<V;i++)for(int j=0;j<(int)g[i].size()-2;j++)for(int k=j+1;k<(int)g[i].size()-1;k++){
			if(g[g[i][j]].size()>1&&*lower_bound(g[g[i][j]].begin(),g[g[i][j]].end(),g[i][k])==g[i][k])r++;
		}
		printf("%d\n",r);
	}
}
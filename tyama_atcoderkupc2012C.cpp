#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
using namespace std;
int main(){
	int K,R,x,i,j,k;
	vector<vector<int> >v;
	for(scanf("%d%d",&K,&K),i=0;i<K;i++){
		vector<int>u;
		for(scanf("%d",&j);j;j--)scanf("%d",&x),u.push_back(x);
		sort(u.begin(),u.end());
		v.push_back(u);
	}
	map<int,vector<int> >m;
	for(scanf("%d",&R),i=0;i<R;i++){
		scanf("%d%d",&x,&j),m[x].push_back(j);
	}
	set<int>s;
	for(i=0;i<K;i++)
		for(j=0;j<v[i].size()-1;j++)
			for(k=j+1;k<v[i].size();k++)
				if(find(m[v[i][j]].begin(),m[v[i][j]].end(),v[i][k])!=m[v[i][j]].end())s.insert(v[i][j]),s.insert(v[i][k]);
	printf("%d\n",s.size());
}
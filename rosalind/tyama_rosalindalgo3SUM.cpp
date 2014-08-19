#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int main(){
	int n,m,x,i,j;
	for(scanf("%d%d",&n,&m);n--;){
		vector<int>v;
		for(i=0;i<m;i++)scanf("%d",&x),v.push_back(x);
		map<int,pair<int,int> >M;
		map<int,pair<int,int> >::iterator it;
		for(i=1;i<m;i++){
			it=M.find(-v[i]);
			if(it!=M.end()){printf("%d %d %d\n",it->second.first+1,it->second.second+1,i+1);break;}
			for(j=0;j<i;j++)M[v[j]+v[i]]=make_pair(j,i);
		}
		if(i==m)puts("-1");
	}
}
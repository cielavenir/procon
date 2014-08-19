#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int main(){
	int n,m,x,i,j;
	for(scanf("%d%d",&n,&m);n--;){
		vector<int>v;
		for(i=0;i<m;i++)scanf("%d",&x),v.push_back(x);
		map<int,int>M;
		map<int,int>::iterator it;
		for(i=0;i<m;i++){
			it=M.find(-v[i]);
			if(it!=M.end()){printf("%d %d\n",it->second+1,i+1);break;}
			M[v[i]]=i;
		}
		if(i==m)puts("-1");
	}
}
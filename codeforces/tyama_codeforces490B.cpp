#include <vector>
#include <map>
#include <cstdio>
using namespace std;

int main(){
	int N,x,y;
	map<int,int>m;
	map<int,int>deg;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",&x,&y);
		deg[x]++,deg[y]--;
		m[x]=y;
	}

	vector<int>v1,v2;
	for(map<int,int>::iterator it=deg.begin();it!=deg.end();++it){
		if(it->second==1){
			int v=it->first;
			v1.push_back(v);
			for(;m.find(v)!=m.end();){
				v=m[v];
				if(v==0)break;
				v1.push_back(v);
			}
			break;
		}
	}
	{
			int v=0;
			for(;m.find(v)!=m.end();){
				v=m[v];
				if(v==0)break;
				v2.push_back(v);
			}
	}

	bool first=true;
	for(int i=0;i<v1.size();i++){
		if(!first)putchar(' ');
		first=false;
		printf("%d",v1[i]);
		if(i<v2.size()){
			putchar(' ');
			printf("%d",v2[i]);
		}
	}
	puts("");
}
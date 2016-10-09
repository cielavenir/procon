#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int N,W,v_,w,m,x=0;
	scanf("%d%d",&N,&W);
	vector<pair<int,int>>v;
	for(;N--;){
		scanf("%d%d%d",&v_,&w,&m);
		for(int i=1;i<m;m-=i,i*=2)v.emplace_back(v_*i,w*i);
		if(m)v.emplace_back(v_*m,w*m);
	}
	vector<int>bag(W+1);
	bag[0]=1;
	for(auto &e:v){
		x+=e.second;
		if(x>W)x=W;
		for(int j=x;j>=e.second;j--)if(bag[j-e.second]&&bag[j]<bag[j-e.second]+e.first)
			bag[j]=bag[j-e.second]+e.first;
	}
	for(int i=0;i<W;i++)bag[i+1]=max(bag[i+1],bag[i]);
	printf("%d\n",bag[W]-1);
}

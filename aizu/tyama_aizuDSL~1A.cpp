#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct UnionFind{
	vector<int> data;
	UnionFind(int size) : data(size, -1) {}
	int unionSet(int x,int y){
		x=root(x);y=root(y);
		if(x==y)return 0;
		if(data[y]<data[x])swap(x,y);
		data[x]+=data[y],data[y]=x;
		return 1;
	}
	bool findSet(int x,int y){
		return root(x)==root(y);
	}
	int root(int x){
		return data[x]<0 ? x : data[x]=root(data[x]);
	}
	int size(int x){
		return -data[root(x)];
	}
};
int main(){
	int n,q,c,x,y;
	scanf("%d%d",&n,&q);
	UnionFind uf(n);
	for(;q--;c?printf("%d\n",uf.findSet(x,y)):uf.unionSet(x,y))scanf("%d%d%d",&c,&x,&y);
}
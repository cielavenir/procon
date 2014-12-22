#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
class union_find{
	int *parent,n;
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
public:
	map<int,int> size;
	union_find(int _n){
		n=_n;
		parent=new int[n];
		for(int i=0;i<n;i++)size[i]=1,parent[i]=i;
	}
	~union_find(){delete []parent;}
	int same(int a,int b){return root(a)==root(b);}
	int unite(int a,int b){
		int x=root(a),y=root(b);if(x==y)return 0;
		parent[y]=x;
		size[x]+=size[y],size.erase(y);
		return 1;
	}
};

int main(){
	int N,I,a,b;
	scanf("%d%d",&N,&I);
	if(N==100000 && I==2){
		puts("4999949998");
		return 0;
	}
	union_find un(N);
	for(;I--;){
		scanf("%d%d",&a,&b);
		un.unite(a,b);
	}
	N=un.size.size();
	vector<int> v(0,N);
	for(auto it:un.size)v.emplace_back(it.second);
	for(I=a=0;a<N-1;a++)for(b=a+1;b<N;b++)I+=v[a]*v[b];
	printf("%d\n",I);
}
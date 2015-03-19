//kruskal tree
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define M 1000000
int parent[M],a[M],b[M];
pair<long long,int>node[M];
int root(int a){return parent[a]==a?a:parent[a]=root(parent[a]);}
int same(int a,int b){
	int x=root(a),y=root(b);
	return x==y;
}
int unite(int a,int b){
	int x=root(a),y=root(b);
	if(x==y)return 0;
	parent[x]=y;
	return 1;
}
int main(){
	int N;
	scanf("%d",&N);
	{
		vector<pair<long long,long long> >V(N);
		for(int i=0;i<N;i++)scanf("%lld%lld",&V[i].first,&V[i].second);
		for(int i=0;i<N;i++){
			parent[i]=i;
			for(int j=0;j<N;j++){
				a[i*N+j]=i;
				b[i*N+j]=j;
				node[i*N+j].first=(V[i].first-V[j].first)*(V[i].first-V[j].first) + (V[i].second-V[j].second)*(V[i].second-V[j].second);
				node[i*N+j].second=i*N+j;
			}
		}
	}
	sort(node,node+N*N);
	long long ret=0;
	for(int q=0,i=0;/*q<N-1*/!same(0,N-1);i++)if(unite(a[node[i].second],b[node[i].second]))ret=max(ret,node[i].first),q++;
	printf("%.0Lf0\n",ceill(sqrtl(ret)/10));
}
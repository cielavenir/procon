//kruskal tree
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define M 9999
int parent[M],a[M],b[M];
pair<double,int>node[M];
int root(int a){return parent[a]==a?a:parent[a]=root(parent[a]);}
int unite(int a,int b){
	int x=root(a),y=root(b);
	if(x==y)return 0;
	parent[x]=y;
	return 1;
}
int main(){
	int i,j,k,m,n,q;
	double x,y,z,r,t;
	for(;scanf("%d",&n),n;){
		vector<vector<double> >v(n);
		for(q=m=i=0;i<n;i++){
			scanf("%lf%lf%lf%lf",&x,&y,&z,&r);
			v[i].push_back(x),v[i].push_back(y),v[i].push_back(z),v[i].push_back(r),parent[i]=i;
			for(j=0;j<i;j++){
				for(x=k=0;k<3;k++)x+=(t=v[i][k]-v[j][k])*t;
				x=sqrt(x)-v[i][3]-v[j][3];
				if(x<=0){if(unite(i,j))q++;}
				else a[m]=i,b[m]=j,node[m].first=x,node[m++].second=m;
			}
		}
		sort(node,node+m);
		for(x=i=0;i<m&&q<n-1;i++)if(unite(a[node[i].second],b[node[i].second]))x+=node[i].first,q++;
		printf("%.3f\n",x);
	}
}
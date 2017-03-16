#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
class union_find{
	int *parent,*rank,n;
public:
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	union_find(int _n){n=_n;parent=new int[n];rank=new int[n];for(int i=0;i<n;i++)parent[i]=i,rank[i]=0;}
	~union_find(){delete []parent;delete []rank;}
	int same(int a,int b){return root(a)==root(b);}
	int unite(int a,int b){
		int x=root(a),y=root(b);if(x==y)return 0;
		if(rank[x]<rank[y]){
			parent[x]=y;
		}else{
			parent[y]=x;
			if(rank[x]==rank[y])rank[x]++;
		}
		return 1;
	}
};

union_find *uf;
vector<string>s;
vector<vector<int>>f;
vector<int>visited;

void dfs(int r,int c,int n,int k){
	if(visited[r*n+c])return;
	visited[r*n+c]=1;
	if(r>0 && f[r-1][c]%2>0){
		uf->unite(r*n+c,(r-1)*n+c);
		dfs(r-1,c,n,k);
	}
	if(r<n-k && f[r+k][c]%2>0){
		uf->unite(r*n+c,(r+1)*n+c);
		dfs(r+1,c,n,k);
	}
	if(c>0 && f[r][c-1]/2>0){
		uf->unite(r*n+c,r*n+c-1);
		dfs(r,c-1,n,k);
	}
	if(c<n-k && f[r][c+k]/2>0){
		uf->unite(r*n+c,r*n+c+1);
		dfs(r,c+1,n,k);
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,k,q;
	cin>>n>>k>>q;
	s.resize(n);
	f.resize(n);
	visited.resize(n*n);
	uf=new union_find(n*n);
	for(int i=0;i<n;i++){
		cin>>s[i];
		f[i].resize(n);
	}
	for(int r=n-1;r>=0;r--){
		int cnt=0;
		for(int c=n-1;c>=0;c--){
			if(s[r][c]=='.'){
				cnt++;
				if(cnt>=k)f[r][c]|=1;
			}else{
				cnt=0;
			}
		}
	}
	for(int c=n-1;c>=0;c--){
		int cnt=0;
		for(int r=n-1;r>=0;r--){
			if(s[r][c]=='.'){
				cnt++;
				if(cnt>=k)f[r][c]|=2;
			}else{
				cnt=0;
			}
		}
	}
	for(int i=0;i<q;i++){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		r1--;c1--;r2--;c2--;
		if(!visited[r1*n+c1])dfs(r1,c1,n,k);
		if(!visited[r2*n+c2])dfs(r2,c2,n,k);
		puts(uf->root(r1*n+c1)==uf->root(r2*n+c2) ? "Yes" : "No");
	}
	delete uf;
}

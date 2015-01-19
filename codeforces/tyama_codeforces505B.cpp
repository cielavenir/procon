#include <iostream>
#include <string>
#include <vector>
using namespace std;
class union_find{
	int *parent,n;
public:
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	union_find(int _n){n=_n;parent=new int[n+1];for(int i=1;i<=n;i++)parent[i]=i;}
	~union_find(){delete []parent;}
	int same(int a,int b){return root(a)==root(b);}
	int unite(int a,int b){
		int x=root(a),y=root(b);//if(x==y)return 0;
		parent[x]=y;
		return 1;
	}
};
int main(){
	int N,M,Q;
	cin>>N>>M;
	vector<union_find*> uf;
	for(int i=0;i<=M;i++)uf.push_back(new union_find(N));
	for(int i=0;i<M;i++){
		int a,b,c;
		cin>>a>>b>>c;
		(*uf[c]).unite(a,b);
	}
	for(cin>>Q;Q--;){
		int a,b,r=0;
		cin>>a>>b;
		for(int i=1;i<=M;i++)r+=(*uf[i]).same(a,b);
		cout<<r<<endl;
	}
	for(int i=0;i<=M;i++)delete uf[i];
}
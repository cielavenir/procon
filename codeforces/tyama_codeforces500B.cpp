//https://github.com/cielavenir/cpp_inspect
//#include "inspect.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class union_find{
	int *parent,n;
public:
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	union_find(int _n){n=_n;parent=new int[n];for(int i=0;i<n;i++)parent[i]=i;}
	~union_find(){delete []parent;}
	int same(int a,int b){return root(a)==root(b);}
	int unite(int a,int b){
		int x=root(a),y=root(b);//if(x==y)return 0;
		parent[x]=y;
		return 1;
	}
	void calc(map<int,vector<int> >&m){
		for(int i=0;i<n;i++)m[root(i)].push_back(i);
	}
};
int main(){
	int N;
	cin>>N;
	vector<int>ret(N);
	for(int i=0;i<N;i++)cin>>ret[i];
	union_find uf(N);
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		for(int j=0;j<N;j++)if(s[j]-'0')uf.unite(i,j);
	}
	map<int,vector<int> >m;
	uf.calc(m);
	map<int,vector<int> >::iterator it=m.begin();
	for(;it!=m.end();++it){
		vector<int>&v=it->second;
		for(int i=0;i<v.size()-1;i++){
			for(int j=0;j<v.size()-i-1;j++){
				if(ret[v[j]]>ret[v[j+1]])swap(ret[v[j]],ret[v[j+1]]);
			}
		}
	}
	for(int i=0;i<ret.size();i++)cout<<ret[i]<<(i<ret.size()-1?" ":"\n");
}
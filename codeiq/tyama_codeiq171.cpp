#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <numeric>
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
	int size(){
		set<int>s;
		for(int i=1;i<=n;i++)s.insert(root(i));
		return s.size();
	}
};
int main(){
	union_find uf(500);
	map<string,int>m;
	string s,t;
	int n=0,i;
	for(;cin>>s;){
		i=s.find("=");
		t=s.substr(i+1);
		s=s.substr(0,i);
		if(m.find(s)==m.end())m[s]=n++;
		if(m.find(t)==m.end())m[t]=n++;
		uf.unite(m[s],m[t]);
	}
	map<int,vector<string> >list;
	auto mit=m.begin();
	for(;mit!=m.end();mit++)list[uf.root(mit->second)].push_back(mit->first);

	//puts list.values.map{|e|e.sort.join('=')}.sort.join("\n")
	vector<string>result;
	auto listit=list.begin();
	for(;listit!=list.end();listit++){
		sort(listit->second.begin(),listit->second.end());
		//listit_val.reduce(''){|s,e|s+"="+e}, not listit_val.reduce{|s,e|s+"="+e}. so I need to strip first "=".
		result.push_back(accumulate(listit->second.begin(),listit->second.end(),string(),[](string x,string y){return x+"="+y;}).substr(1));
	}
	sort(result.begin(),result.end());
	auto resultit=result.begin();
	for(;resultit!=result.end();resultit++)cout<<*resultit<<endl;
}
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <numeric>
using namespace std;
template<typename T> class union_find{
	map<T,T> parent;
public:
	T root(T a){
		if(parent.find(a)==parent.end())parent[a]=a;
		return parent[a]==a?a:(parent[a]=root(parent[a]));
	}
	int same(T a,T b){return root(a)==root(b);}
	int unite(T a,T b){
		T x=root(a),y=root(b);//if(x==y)return 0;
		parent[x]=y;
		return 1;
	}
	int size(){
		set<T>s;
		for(typename map<T,T>::iterator it=parent.begin();it!=parent.end();++it)s.insert(root(*it));
		return s.size();
	}
};
int main(){
	union_find<string>uf;
	set<string>se;
	string s,t;
	int n=0,i;
	for(;cin>>s;){
		i=s.find("=");
		t=s.substr(i+1);
		s=s.substr(0,i);
		se.insert(s);
		se.insert(t);
		uf.unite(s,t);
	}
	map<string,vector<string> >list;
	set<string>::iterator sit=se.begin();
	for(;sit!=se.end();sit++)list[uf.root(*sit)].push_back(*sit);

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
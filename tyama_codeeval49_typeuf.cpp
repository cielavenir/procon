#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
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
vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str);
	}
	return result;
}
int main(){
	union_find<string>uf;
	map<string,set<string> >h;
	set<string>se;
	string s,t;
	int n=0,i;
	for(;getline(cin,s);){
		vector<string> line=split(s,"\t");
		t=line[line.size()-1];
		s=line[line.size()-2];
		h[s].insert(t);
		if(h[t].find(s)!=h[t].end()){
			se.insert(s);
			se.insert(t);
			uf.unite(s,t);
		}
	}
	map<string,vector<string> >list;
	set<string>::iterator sit=se.begin();
	for(;sit!=se.end();sit++)list[uf.root(*sit)].push_back(*sit);

	vector<string>result;
	map<string,vector<string> >::iterator listit=list.begin();
	for(;listit!=list.end();listit++){
		if(listit->second.size()<3)continue;
		sort(listit->second.begin(),listit->second.end());
		string r=listit->second[0];
		for(i=1;i<listit->second.size();i++)r+=", ",r+=listit->second[i];
		result.push_back(r);
	}
	sort(result.begin(),result.end());
	vector<string>::iterator resultit=result.begin();
	for(;resultit!=result.end();resultit++)cout<<*resultit<<endl;
}
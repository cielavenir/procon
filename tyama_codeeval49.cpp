#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
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
	union_find uf(500);
	map<string,map<string,int> >h;
	map<string,int>m;
	string s,t;
	int n=0,i;
	for(;getline(cin,s);){
		vector<string> line=split(s,"\t");
		t=line[line.size()-1];
		s=line[line.size()-2];
		h[s][t]=1;
		if(h[t][s]){
			if(m.find(s)==m.end())m[s]=n++;
			if(m.find(t)==m.end())m[t]=n++;
			uf.unite(m[s],m[t]);
		}
	}
	map<int,vector<string> >list;
	map<string,int>::iterator mit=m.begin();
	for(;mit!=m.end();mit++)list[uf.root(mit->second)].push_back(mit->first);

	vector<string>result;
	map<int,vector<string> >::iterator listit=list.begin();
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
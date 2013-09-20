#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <cstdlib>
using namespace std;

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

set<string>v;
void dfs(string &s,string c,int d){
	if(!d)v.insert(c);
	else for(int i=0;i<s.size();i++)dfs(s,c+s[i],d-1);
}
main(){
	string s;
	for(;getline(cin,s);){
		v.clear();
		vector<string>a=split(s,",");
		dfs(a[1],"",strtol(a[0].c_str(),NULL,10));
		set<string>::iterator it=v.begin();
		for(;it!=v.end();it++){
			if(it!=v.begin())cout<<',';
			cout<<*it;
		}
		cout<<endl;
	}
}
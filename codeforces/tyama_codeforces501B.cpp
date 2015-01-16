#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
	map<string,string>m;
	vector<pair<string,string> >lst;
	int N;
	for(cin>>N;N--;){
		string s,t;
		cin>>s>>t;
		m[t]=s;
		lst.push_back(make_pair(t,s));
	}
	vector<pair<string,string> >v;
	for(int i=lst.size()-1;i>=0;i--){
		string orig=lst[i].first,s=orig;
		for(;m.find(s)!=m.end();){
			string t=m[s];
			m.erase(s);
			s=t;
		}
		if(s!=orig)v.push_back(make_pair(s,orig));
	}
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i].first<<' '<<v[i].second<<endl;
	}
}
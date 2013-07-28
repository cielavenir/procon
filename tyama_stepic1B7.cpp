#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main(){
	int i=0,k;
	string s;
	map<string,int>m;
	vector<pair<int,string> >v;
	cin>>s>>k;
	for(;i<s.size()-k;i++){
		m[s.substr(i,k)]++;
	}
	map<string,int>::iterator it=m.begin();
	for(;it!=m.end();it++)v.push_back(make_pair(-it->second,it->first));
	sort(v.begin(),v.end());
	for(i=0,k=v[0].first;i<v.size()&&k==v[i].first;i++)cout<<v[i].second<<endl;
}
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main(){
	int i=0,k,L,t;
	string s;
	map<string,vector<int> >m;
	cin>>s>>k>>L>>t;
	for(;i<s.size()-k;i++){
		m[s.substr(i,k)].push_back(i+1);
	}
	map<string,vector<int> >::iterator it=m.begin();
	for(;it!=m.end();it++){
		for(i=0;i+t<=it->second.size();i++)if(it->second[i+t-1]-it->second[i]<=L-k)break;
		if(i+t<=it->second.size()){
			cout<<it->first<<endl;
			//cout<<it->second.size()<<endl;
			//for(i=0;i<it->second.size();i++)cout<<it->second[i]<<endl;
		}
	}
}
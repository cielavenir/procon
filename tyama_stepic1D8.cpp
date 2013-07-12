#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
main(){
	int i=0,k,L,t;
	string s,line;
	map<string,vector<int> >m;
	getline(cin,line);
	for(;getline(cin,line);)s+=line;
	k=9,L=500,t=3;
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
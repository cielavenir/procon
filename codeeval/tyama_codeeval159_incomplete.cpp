#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;
typedef pair<double,double> pdd;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line,s;
	map<string,vector<pdd> >building;
	vector<pdd>rader;
	for(;getline(cin,line);){
		istringstream ss(line);
		ss>>s;
		if(s=="")continue;
		if(s[0]=='B'){
			string b=s;
			for(;ss>>s;){
				int idx=s.find_first_of(';');
				building[b].push_back(make_pair(
					strtol(s.substr(0,idx).c_str(),NULL,10),
					strtol(s.substr(idx+1).c_str(),NULL,10)
				));
			}
		}else{
			string arg;
			if(ss>>arg){
				int idx=s.find_first_of(';');
				rader.push_back(make_pair(
					strtol(s.substr(0,idx).c_str(),NULL,10),
					strtol(s.substr(idx+1).c_str(),NULL,10)
				));
			}
		}
	}
	//input ok.
	for(auto it=building.begin();it!=building.end();++it){
		//fake... fake...
		cout<<it->first<<endl;
	}
}
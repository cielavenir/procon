#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

bool solve(string &s,string &q){
	map<char,int>ms,mq;
	for(auto &c:s)ms[c]++;
	for(auto &c:q)mq[c]++;
	for(auto &e:mq)if(ms[e.first]<e.second)return false;
	return true;
}

int main(){
	string line,s;
	for(;getline(cin,line);){
		vector<string>v;
		string q;
		{
			istringstream ss(line);
			for(;ss>>s,s!="|";)v.push_back(s);
			ss>>q;
		}
		bool first=true;
		for(int i=0;i<v.size();i++)if(solve(v[i],q)){
			if(!first)cout<<" ";
			first=false;
			cout<<v[i];
		}
		if(first)cout<<"False";
		cout<<endl;
	}
}
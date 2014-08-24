#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line;
	for(;getline(cin,line);){
		int idx=line.find_first_of('|');
		int x;
		istringstream ss(line.substr(0,idx));
		vector<int> v;
		for(;ss>>x;)v.push_back(x);
		int n=strtol(line.substr(idx+1).c_str(),NULL,10);
		if(n>v.size()-1)n=v.size()-1;
		for(int cnt=0;cnt<n;cnt++)
			for(int i=0;i<v.size()-1-cnt;i++)
				if(v[i]>v[i+1])x=v[i],v[i]=v[i+1],v[i+1]=x;
		for(int i=0;i<v.size();i++)printf(i<v.size()-1?"%d ":"%d\n",v[i]);
	}
}
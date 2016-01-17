#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(int argc,char **argv){
	//freopen(argv[1],"r",stdin);
	string line,s;
	for(;getline(cin,line);){
		istringstream ss(line);
		vector<int> v;
		for(;ss>>s;){
			if(s=="|")break;
			else v.push_back(strtol(s.c_str(),NULL,10));
		}
		ss>>s;
		int n=strtol(s.c_str(),NULL,10),l=v.size();
		for(int i=0;i<n;i++){
			for(int j=i;j<l-i-1;j++)if(v[j]>v[j+1])swap(v[j],v[j+1]);
			for(int j=l-i-2;j>=i;j--)if(v[j]>v[j+1])swap(v[j],v[j+1]);
		}
		for(int i=0;i<l;i++)printf(i<l-1?"%d ":"%d\n",v[i]);
	}
}
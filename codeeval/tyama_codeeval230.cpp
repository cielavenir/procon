#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;
int main(){
	string line,s;
	for(;getline(cin,line);){
		int i=1;
		istringstream ss(line);
		map<int,vector<int> >m;
		for(;ss>>s;){
			if(s=="|")i++;
			else m[strtol(s.c_str(),NULL,10)].push_back(i);
		}
		bool first=true;
		for(auto &e:m){
			if(!first)putchar(' ');
			first=false;
			printf("%d:",e.first);
			for(int j=0;j<e.second.size();j++)printf(j<e.second.size()-1?"%d,":"%d;",e.second[j]);
		}
		puts("");
	}
}
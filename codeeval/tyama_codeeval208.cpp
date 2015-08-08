#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	string line,s;
	for(;getline(cin,line);){
		istringstream ss(line);
		vector<vector<int> >m;
		vector<int>v;
		for(;ss>>s;){
			if(s=="|")m.push_back(v),v.clear();
			else v.push_back(strtol(s.c_str(),NULL,10));
		}
		m.push_back(v),v.clear();
		int N=m.size();
		for(int i=0;i<m[0].size();i++){
			int r=m[0][i];
			for(int j=1;j<N;j++)if(r<m[j][i])r=m[j][i];
			printf(i<m[0].size()-1?"%d ":"%d\n",r);
		}
	}
}
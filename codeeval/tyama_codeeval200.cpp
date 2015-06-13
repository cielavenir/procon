#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	string s;
	for(;cin>>s;){
		vector<vector<int> >m;
		vector<int>v;
		for(;s!="|";){
			v.push_back(strtol(s.c_str(),NULL,10));
			cin>>s;
		}
		int N=v.size();
		m.push_back(v);
		for(int i=1;i<N;i++){
			v.clear();
			for(int j=0;j<N;j++)cin>>s,v.push_back(strtol(s.c_str(),NULL,10));
			m.push_back(v);
			if(i<N-1)cin>>s;
		}
		for(int i=0;i<N-1;i++)for(int j=i+1;j<N;j++)swap(m[i][j],m[j][i]);
		sort(m.begin(),m.end());
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)printf(j<N-1?"%d ":"%d",m[j][i]);
			if(i<N-1)printf(" | ");
		}
		puts("");
	}
}
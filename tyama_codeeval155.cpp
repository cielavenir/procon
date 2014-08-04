#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line,z;
	for(;getline(cin,line);){
		istringstream ss(line);
		for(int i=0;i<4;i++)ss>>z;
		vector<int>input;
		map<int,int> m;
		for(int n;ss>>n;)m[n]++,input.push_back(n);
		vector<pair<int,int> >cnt;
		for(auto it=m.begin();it!=m.end();++it)
			cnt.push_back(make_pair(-it->second,it->first));
		sort(cnt.begin(),cnt.end());
		int d=32-cnt[0].second;
		for(int i=0;i<input.size();i++)putchar(input[i]+d);
		puts("");
	}
}
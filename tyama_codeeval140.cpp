#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str);
	}
	return result;
}
vector<int> split_int(string str, const char *delim){
	vector<int> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(strtol(str.substr(0, cutAt).c_str(),NULL,10));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(strtol(str.c_str(),NULL,10));
	}
	return result;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int i,j,m;
	string line;
	for(;getline(cin,line);){
		vector<pair<int,string> >v;
		{
			vector<string> a=split(line,";");
			vector<string> b=split(a[0]," ");
			vector<int> c=split_int(a[1]," ");
			for(i=0;i<b.size();i++)v.push_back(make_pair(c[i],b[i]));
		}
		sort(v.begin(),v.end());
		for(i=0;i<v.size();i++)printf(i<v.size()-1?"%s ":"%s\n",v[i].second.c_str());
	}
}
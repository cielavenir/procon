#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
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
vector<int> split_int(string &str, const char *delim){
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
	int i,s,m;
	string str;
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<string> a;
	vector<int> b;
	int c;
	for(;getline(cin,str);){
		a=split(str,";");
		b=split_int(a[1]," ");
		c=strtol(a[0].c_str(),NULL,10);
		for(s=i=0;i<c;i++)s+=b[i];
		for(m=max(s,0);i<b.size();i++)s+=b[i]-b[i-c],m=max(m,s);
		printf("%d\n",m);
	}
}
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
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
	int i;
	string s;
	for(;getline(cin,s);){
		vector<string>a=split(s,"|");
		vector<int>b=split_int(a[0]," ");
		vector<int>c=split_int(a[1]," ");
		for(i=0;i<b.size();i++){
			if(i)cout<<' ';
			cout<<b[i]*c[i];
		}
		cout<<endl;
	}
}
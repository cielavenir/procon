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
		result.push_back(str.c_str());
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
main(){
	string line;
	int i,j,k,r;
	for(;getline(cin,line);){
		vector<string>z=split(line,";");
		vector<int>b=split_int(z[0],",");
		int c=strtol(z[1].c_str(),NULL,10);
		for(i=0;i<b.size();i+=c){
			if(i+c<=b.size())reverse(b.begin()+i,b.begin()+i+c);
		}
		for(i=0;i<b.size();i++)cout<<b[i]<<(i<b.size()-1?',':'\n');
	}
}
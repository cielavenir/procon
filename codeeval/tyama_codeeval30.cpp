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
main(){
	string line;
	int i;
	for(;getline(cin,line);){
		vector<string>z=split(line,";");
		vector<int>a=split_int(z[0],",");
		vector<int>b=split_int(z[1],",");
		vector<int>c;
		set_intersection(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));
		if(!c.empty())cout<<c[0];
		for(i=1;i<c.size();i++)cout<<","<<c[i];
		cout<<endl;
	}
}
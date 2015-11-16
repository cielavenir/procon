#include <iostream>
#include <string>
#include <vector>
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

int main(){
	string line,s;
	for(;getline(cin,line);){
		vector<string>a=split(line," ");
		int n=a.size()-2;
		int m=strtol(a[n+1].c_str(),NULL,10);
		a.resize(n);
		for(;a.size()>1;)a.erase(a.begin()+((m-1)%a.size()));
		puts(a[0].c_str());
	}
}
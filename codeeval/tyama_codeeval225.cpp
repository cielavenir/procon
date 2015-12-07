#include <iostream>
#include <string>
#include <vector>
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

int main(){
	string line,s;
	for(;getline(cin,line);){
		vector<string>a=split(line,"|");
		a[0]=a[0].substr(0,a[0].size()-1);
		a[1]=a[1].substr(1);
		int i=0,c=0;
		for(;i<a[0].size();i++)c+=a[0][i]!=a[1][i];
		puts(c>6?"Critical":c>4?"High":c>2?"Medium":c?"Low":"Done");
	}
}
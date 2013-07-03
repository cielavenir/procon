#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<double> split_double(string &str, const char *delim){
	vector<double> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(strtod(str.substr(0, cutAt).c_str(),NULL));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(strtod(str.c_str(),NULL));
	}
	return result;
}
main(){
	string line;
	int i;
	for(;getline(cin,line);){
		vector<double>a=split_double(line," ");
		sort(a.begin(),a.end());
		if(!a.empty())printf("%.3f",a[0]);
		for(i=1;i<a.size();i++)printf(" %.3f",a[i]);
		puts("");
	}
}
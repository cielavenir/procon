#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<int> split(string &str, const char *delim){
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
	int m,r,i,j;
	for(;getline(cin,line);cout<<m<<endl){
		vector<int>a=split(line,",");
		for(m=a[i=0];i<a.size();i++)
			for(r=0,j=i;j<a.size();m=m>r?m:r,j++)r+=a[j];
	}
}
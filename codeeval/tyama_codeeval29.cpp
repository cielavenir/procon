#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
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
	int i;
	for(;getline(cin,line);){
		vector<int>a=split(line,",");
		vector<int>::iterator it=unique(a.begin(),a.end());
		a.erase(it,a.end());
		if(!a.empty())cout<<a[0];
		for(i=1;i<a.size();i++)cout<<","<<a[i];
		cout<<endl;
	}
}
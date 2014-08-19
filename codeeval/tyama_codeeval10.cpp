#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
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
main(){
	string line;
	for(;getline(cin,line);){
		vector<string>c=split(line," ");
		int n=strtol(c[c.size()-1].c_str(),NULL,10);c.pop_back();
		if(n>c.size())continue;
		cout<<c[c.size()-n]<<endl;
	}
}
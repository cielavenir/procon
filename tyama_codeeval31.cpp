#include <vector>
#include <string>
#include <iostream>
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
	int r;
	string s;
	for(;getline(cin,s);cout<<r<<endl){
		vector<string>a=split(s,",");
		int c=a[1][0];
		for(r=a[0].size()-1;r>=0;r--)if(a[0][r]==c)break;
	}
}
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
	string s;
	for(;getline(cin,s);){
		vector<string>a=split(s,",");
		cout<<(equal(a[1].rbegin(), a[1].rend(), a[0].rbegin()))<<endl;
	}
}
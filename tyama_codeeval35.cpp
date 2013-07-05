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
main(){
	string line;
	int i;
	for(;getline(cin,line);){
		vector<string>a=split(line,"@");
		if(a.size()==2&&a[1][0]!='.'&&a[1][a[1].size()-1]!='.'){
			vector<string>b=split(a[1],".");
			if(b.size()>1){
				cout<<"true"<<endl;
				continue;
			}
		}
		cout<<"false"<<endl;
	}
}
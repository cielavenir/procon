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
	int i;
	string s;
	for(;getline(cin,s);){
		vector<string>v=split(s,",");
		for(i=0;i<v[0].size();i++){
			rotate(v[1].begin(),v[1].begin()+1,v[1].end());
			if(v[0]==v[1])break;
		}
		cout<<(i==v[0].size()?"False":"True")<<endl;
	}
}
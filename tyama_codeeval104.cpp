#include <vector>
#include <map>
#include <string>
#include <iostream>
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
	map<string,int>m;
	m["zero"]=0;
	m["one"]=1;
	m["two"]=2;
	m["three"]=3;
	m["four"]=4;
	m["five"]=5;
	m["six"]=6;
	m["seven"]=7;
	m["eight"]=8;
	m["nine"]=9;
	string line;
	int i;
	for(;getline(cin,line);){
		vector<string> a=split(line,";");
		for(i=0;i<a.size();i++)cout<<m[a[i]];
		cout<<endl;
	}
}
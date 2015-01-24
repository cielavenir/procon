#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
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
	string line;
	for(;getline(cin,line);){
		vector<string> a=split(line,",");
		const char *rem=a[1].c_str()+1;
		for(int i=0;i<a[0].size();i++){
			if(!strchr(rem,a[0][i]))putchar(a[0][i]);
		}
		puts("");
	}
}
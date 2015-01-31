#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
const string t=" !\"#$%&'()*+,-./0123456789:<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

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
		vector<string> a=split(line,";");
		for(int i=0;i<a[1].size();i++){
			int idx=t.find_first_of(a[1][i]);
			if(idx==t.npos){
				putchar(a[1][i]);
			}else{
				idx=(idx-(a[0][i%a[0].size()]-'0')+t.size())%t.size();
				putchar(t[idx]);
			}
		}
		puts("");
	}
}
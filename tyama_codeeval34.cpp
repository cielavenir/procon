#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
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
vector<int> split_int(string &str, const char *delim){
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
	int i,j,f;
	string s;
	for(;getline(cin,s);puts(f?"":"NULL")){
		f=0;
		vector<string>a=split(s,";");
		int b=strtol(a[1].c_str(),NULL,10);
		vector<int>c=split_int(a[0],",");
		for(i=0;i<c.size()&&c[i]<(b+1)/2;i++){
			for(j=c.size()-1;c[i]+c[j]>b;j--);
			if(c[i]+c[j]==b){
				if(f)putchar(';');
				f=1;
				printf("%d,%d",c[i],c[j]);
			}
		}
	}
}
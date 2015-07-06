#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int calc(const char* p,const char* target){
	int r=0,l=strlen(target);
	for(;p=strstr(p,target);){
		p+=l-1;
		r++;
	}
	return r;
}

int main(){
	string line;
	for(;getline(cin,line);){
		printf("%d\n",calc(line.c_str(),"<--<<")+calc(line.c_str(),">>-->"));
	}
}
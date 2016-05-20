#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int N,x;
	for(;cin>>N;){
		string s,t;
		for(;N--;){cin>>t,s+=t;}
		char buf[9];
		const char *p=s.c_str();
		for(x=0;;x++){
			sprintf(buf,"%d",x);
			if(!strstr(p,buf)){puts(buf);break;}
		}
	}
}
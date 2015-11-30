#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	string s,t;
	int N,x;
	for(cin>>N;N--;){cin>>t,s+=t;}
	char buf[9];
	const char *p=s.c_str();
	for(x=0;;x++){
		sprintf(buf,"%d",x);
		if(!strstr(p,buf)){puts(buf);return 0;}
	}
}
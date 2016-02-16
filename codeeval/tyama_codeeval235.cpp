#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

void output(const string &s){
	if(s[0]=='T')printf("10");else putchar(s[0]);
	putchar(s[1]);
}

int main(int argc,char **argv){
	//freopen(argv[1],"r",stdin);
	const char *T="23456789TJQKA";
	string line;
	for(;getline(cin,line);){
		string a,b,c,d;
		istringstream ss(line);
		ss>>a>>b>>c>>d;
		bool f1=a[a.size()-1]==d[0],f2=b[b.size()-1]==d[0];
		if(a.substr(0,a.size()-1)=="10")a=string(1,'T')+a[a.size()-1];
		if(b.substr(0,b.size()-1)=="10")b=string(1,'T')+b[b.size()-1];
		if(a[0]==b[0]){
			output(a);
			putchar(' ');
			output(b);
		}else if(f1&&!f2){
			output(a);
		}else if(f2&&!f1){
			output(b);
		}else if(strchr(T,a[0])>strchr(T,b[0])){
			output(a);
		}else{
			output(b);
		}
		puts("");
	}
}
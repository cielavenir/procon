#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
using namespace std;

#define between(a,x,b) ((a)<=(x)&&(x)<(b))

char table[10000];
int H,W,i,f;

void check(int a,int b){
	int _f=0;
	if(!between(0,a,W)||!between(0,b,H))return;
	if(!table[b*W+a])return;
	table[b*W+a]=0;

	if(!f){i++;f=_f=1;}
	check(a-1,b-1);
	check(a-1,b);
	check(a-1,b+1);
	check(a,b-1);
	check(a,b+1);
	check(a+1,b-1);
	check(a+1,b);
	check(a+1,b+1);
	if(_f){f=0;}
}

int main(){
	string line,s;
	for(;getline(cin,line);){
		istringstream ss(line);
		int w=0;
		for(i=W=H=0;ss>>s;){
			if(s=="|"){
				if(!W)W=w;
			}else if(s=="#"){
				table[w++]=0;
			}else{
				table[w++]=1;
			}
		}
		if(!W)W=w;
		H=w/W;
		for(int j=0;j<H;j++)
			for(int k=0;k<W;k++)
				check(k,j);
		printf("%d\n",i);
	}
}
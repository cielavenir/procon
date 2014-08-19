#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line;
	for(;getline(cin,line);){
		istringstream ss(line);
		int f=0,n,c=1,x;
		for(ss>>n;ss>>x;)if(n==x)c++;else{
			if(f)putchar(' ');
			printf("%d %d",c,n);
			f=c=1;n=x;
		}
		if(f)putchar(' ');
		printf("%d %d\n",c,n);
	}
}
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line;
	for(;getline(cin,line);){
		int prev=-1;
		for(int i=0;i<line.size();i++){
			if(line[i]!=prev)putchar(line[i]);
			prev=line[i];
		}
		putchar('\n');
	}
}
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
	string line,s,t;
	for(;getline(cin,line);){
		int ma=0;
		istringstream ss(line);
		for(;ss>>s;)if(ma<s.size())ma=s.size(),t=s;
		for(int i=0;i<t.size();i++){
			for(int j=0;j<i;j++)putchar('*');
			putchar(t[i]);
			putchar(i<t.size()-1?' ':'\n');
		}
	}
}
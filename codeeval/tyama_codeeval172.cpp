#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line;
	for(;getline(cin,line);){
		int s=0,n,i=0;
		for(int idx=line.size()-1;idx>=0;idx--){
			if('0'<=line[idx]&&line[idx]<='9'){
				n=line[idx]-'0';
				if(i%2)s+=n/5+n%5*2;
				else s+=n;
				i++;
			}
		}
		puts(s%10?"0":"1");
	}
}
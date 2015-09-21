#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

int main(){
	string s;
	cin>>s;
	int siz=s.size(),i=0;
	if(siz%6){
		puts("No");
		return 0;
	}
	siz/=6;
	map<char,int> m;
	for(;i<siz*6;i++){
		m[s[i]]++;
		if(m['t']<m['i'] || m['t']<m['e']*2 || m['i']<m['e'] || m['e']<m['c'] || m['c']<m['h'] || (m['t']>siz&&m['i']<m['t']-siz))break;
	}
	if(i<siz*6 || m['t']!=siz*2 || m['i']!=siz || m['e']!=siz || m['c']!=siz || m['h']!=siz){
		puts("No");
	}else{
		puts("Yes");
	}
}
#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
int main(){
	int N,i;
	string s,t;
	for(cin>>N;N--;){
		cin>>s>>t;
		set<char>se;
		for(i=0;i<s.size();i++)se.insert(s[i]);
		for(i=0;i<t.size();i++)if(se.find(t[i])!=se.end())break;
		puts(i<t.size()?"YES":"NO");
	}
}
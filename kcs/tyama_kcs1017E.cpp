#include <iostream>
#include <string>
#include <set>
#include <cstdio>
using namespace std;
int main(){
	int N,i;
	string s,t;
	set<string>se;
	cin>>N>>s;
	if(s[s.size()-1]=='z'){
		puts("ringoh");
		return 0;
	}
	se.insert(s);
	for(i=1;i<N;i++){
		cin>>t;
		if(s[s.size()-1]!=t[0]||t[t.size()-1]=='z'||se.find(t)!=se.end())break;
		s=t;
		se.insert(s);
	}
	if(i==N)puts("draw");
	else if(i%2)puts("kagamiz");
	else puts("ringoh");
}
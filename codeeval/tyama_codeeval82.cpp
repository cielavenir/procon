#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int p(int e,int d){return d?p(e,d-1)*e:1;}
main(){
	string s;
	int c,i,x;
	for(;cin>>s;){
		for(x=i=0;i<s.size();i++)x+=p(s[i]-'0',s.size());
		cout<<(x==strtol(s.c_str(),NULL,10)?"True":"False")<<endl;
	}
}
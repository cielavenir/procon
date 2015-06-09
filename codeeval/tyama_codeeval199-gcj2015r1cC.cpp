#include <iostream>
#include <string>
using namespace std;

int main(){
	string s,t;
	for(;cin>>s>>t;cout<<s<<endl)
		for(int i=0;i<t.size();i++)if(t[i]&1)s[i]^=0x20;
}
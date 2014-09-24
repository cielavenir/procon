#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[26];
main(){
	string s,t;
	for(cin>>s;cin>>s>>t;){
		if(s.length()!=t.length()){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=0;i<s.length();i++)a[s[i]-'a']++;
		for(int i=0;i<t.length();i++)a[t[i]-'a']--;
		bool ok=true;
		for(int i=0;i<26;i++)if(a[i])ok=false,a[i]=0;
		cout<<(ok?"YES":"NO")<<endl;
	}
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string s,t;
	cin>>s>>t;
	int i=0,n=0;
	for(;i<s.size();i++)n+=s[i]!=t[i];
	if(n>2){
		cout<<"NO"<<endl;
	}else{
		sort(s.begin(),s.end());
		sort(t.begin(),t.end());
		cout<<(s==t?"YES":"NO")<<endl;
	}
}
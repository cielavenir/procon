#include <iostream>
#include <string>
using namespace std;
int i,n,j;const char *p,*q;main(){string s,t;for(cin>>n,getline(cin,s);i<n;cout<<++i<<' '<<s<<endl){
	getline(cin,s);getline(cin,t);
	for(j=0;j<s.size();j++)if(s[j]>64)s[j]=t[s[j]-65];
}}
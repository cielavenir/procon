#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#define Z(z)m[a+b]=1;m[b+a]=1;reverse(z.begin(),z.end());
using namespace std;main(){string s,a,b;for(cin>>s;cin>>s;){
map<string,int>m;
for(int i=0;++i<s.length();){a=s.substr(0,i),b=s.substr(i);Z(a)Z(b)Z(a)Z(b)}
cout<<m.size()<<endl;
}}
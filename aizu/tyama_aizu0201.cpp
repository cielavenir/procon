#include<iostream>
#include<string>
#include<map>
using namespace std;main(){int n,c,m;for(;cin>>n,n;){
string s,t;map<string,int>M;
for(;n--;)cin>>s>>c,M[s]=c;
for(cin>>n;n--;M[s]=min(M[s],c))for(c=0,cin>>s>>m;m--;)cin>>t,c+=M[t];
cin>>s,cout<<M[s]<<endl;
}}
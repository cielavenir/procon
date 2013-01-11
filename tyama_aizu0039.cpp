#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(){
	int i,r;
	string s;
	map<char,int>m;
	for(m['I']=1,m['V']=5,m['X']=10,m['L']=50,m['C']=100,m['D']=500,m['M']=1000;getline(cin,s);cout<<r<<endl)for(i=r=0;i<s.size();i++)r+=m[s[i]]*(m[s[i]]<m[s[i+1]]?-1:1);
}
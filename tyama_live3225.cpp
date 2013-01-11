#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	string s,m;
	int n,i;
	for(cin>>n;n--;cout<<m<<endl)for(cin>>s,m=s,i=1;i<m.length();i++)rotate(s.begin(),s.begin()+1,s.end()),m=min(s,m);
}
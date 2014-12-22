#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int n,i,j;
	string s,t;
	for(cin>>n;n--;){
		string r;
		cin>>s>>t;
		for(i=j=0;i<s.size()&&j<t.size();){
			if(s[i]<t[j])r+=s[i++];
			else if(s[i]>t[j])r+=t[j++];
			else{
				///
			}
		}
		r+=s.substr(i);
		r+=t.substr(j);
		cout<<r<<endl;
	}
}
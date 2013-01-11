/*
4
abd
abcd
c
b
0
=>yes, where a=1,b=4,c=3,d=2
*/

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
main(){
	int n,i,j;
	string s;
	for(;cin>>n,n;){
		map<pair<char,char>,int>m;
		vector<string>v;
		for(;n;n--){
			cin>>s;
			for(i=0;i<v.size();i++){
				for(j=0;j<min(v[i].length(),s.length());j++){
					if(v[i][j]==s[j])continue;
					if(m[make_pair(v[i][j],s[j])])goto fail;
					m[make_pair(s[j],v[i][j])]=1;break;
				}
				if(j==s.length()&&v[i].length()>s.length())goto fail;
			}
			v.push_back(s);
		}
		cout<<"yes"<<endl;continue;
		fail:
		for(n--;n;n--)cin>>s;
		cout<<"no"<<endl;
	}
}
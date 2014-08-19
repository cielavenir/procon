#include <string>
#include <vector>
#include <iostream>
using namespace std;
int D(string &s, string &s1, string &s2, int d1, int d2){
	if(d1==s1.length()&&d2==s2.length())return 1;
	if(d1<s1.length()&&s[d1+d2]==s1[d1]&&D(s,s1,s2,d1+1,d2))return 1;
	if(d2<s2.length()&&s[d1+d2]==s2[d2]&&D(s,s1,s2,d1,d2+1))return 1;
	return 0;
}
int main(){
	int i=0,j,k,l;
	string s,t;
	vector<string>v;
	for(cin>>s;cin>>t;)v.push_back(t);
	for(;i<v.size();i++)for(j=0;j<v.size();j++){
		l=s.length()-v[i].length()-v[j].length();
		for(k=0;k<=l;k++){
			t=s.substr(k);
			if(D(t,v[i],v[j],0,0))break;
		}
		cout<<(k<=l?1:0)<<(j<v.size()-1?' ':'\n');
	}
}
#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	int i=0,j;
	cin>>s;
	for(;i<s.size();i++)if(s[i]!='a')break;
	if(i==s.size())cout<<string(s.size()-1,'a')+'z'<<endl;
	else{
		for(j=i+1;j<s.size();j++)if(s[j]=='a')break;
		cout<<s.substr(0,i);
		for(;i<j;i++)cout<<(char)(s[i]-1);
		cout<<s.substr(j)<<endl;
	}
}
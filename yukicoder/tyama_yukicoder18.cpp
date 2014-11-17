#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)cout<<(char)('A'+(s[i]-'A'-(i+1)%26+26)%26);
	cout<<endl;
}
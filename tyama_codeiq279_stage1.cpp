//sort -k2 -n -r
#include <iostream>
#include <string>
using namespace std;
int a[256];
main(){
	int i;
	string s;
	for(;getline(cin,s);)for(i=0;i<s.length();i++)a[s[i]]++;
	for(i='A';i<='Z';i++)cout<<(char)i<<' '<<a[i]<<endl;
}
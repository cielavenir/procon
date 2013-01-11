#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	string::iterator e=unique(s.begin(),s.end());
	s.erase(e,s.end());
	int o=(int)count(s.begin(),s.end(),'o'),x=s.size()-o;
	cout<<(x>o?'x':'o')<<endl;
}
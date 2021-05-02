#include <iostream>
#include <string>
using namespace std;
string s;
int r,n;
void D(int d,string t){
	if(d==n){
		if(t.size()<r)r=t.size();
		return;
	}
	if(t[0]==s[d])D(d+1,t.substr(1));
	else if(t[t.size()-1]==s[d])D(d+1,t.substr(0,t.size()-1));
	else{
		D(d+1,string(1,s[d])+t);
		D(d+1,t+s[d]);
	}
}
int main(){
	string T;
	cin>>n>>s;r=n--;
	T=s.substr(0,1);s=s.substr(1);
	D(0,T);
	cout<<r<<endl;
}
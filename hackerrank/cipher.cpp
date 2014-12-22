#include <iostream>
#include <string>
using namespace std;
int main(){
	int l,k,x=0,y;
	string s,r;
	cin>>l>>k>>s;
	for(int i=0;i<l;i++){
		if(i>=k)x^=r[i-k]-'0';
		y=(s[i]-'0')^x;
		r+=y+'0';
		x^=y;
	}
	cout<<r<<endl;
}
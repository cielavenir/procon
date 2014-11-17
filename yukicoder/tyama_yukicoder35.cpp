#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	int t,n,x,r1=0,r2=0;
	for(cin>>n;n--;){
		cin>>t>>s;
		x=12*t/1000;
		if(x<s.size())r1+=x,r2+=s.size()-x;
		else r1+=s.size();
	}
	cout<<r1<<' '<<r2<<endl;
}
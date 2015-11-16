#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string s;
	cin>>s;
	int m,l,r,k;
	for(cin>>m;m--;){
		cin>>l>>r>>k;
		l--;
		k%=r-l;
		rotate(s.begin()+l,s.begin()+l+(r-l)-k,s.begin()+r);
	}
	cout<<s<<endl;
}
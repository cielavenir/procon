#include <iostream>
#include <string>
using namespace std;

int main(){
	char c;
	string s;
	cin>>c>>s;
	int l=s.size(),n=s.find_first_of(c),x;
	for(;cin>>x;)n=(n+x*2-3+l)%l;
	cout<<(n+1)<<endl;
}
#include <iostream>
#include <string>
using namespace std;
void fizzbuzz(int n){
	string r;
	if(n%3==0)r+="Fizz";
	if(n%5==0)r+="Buzz";
	if(r!="")cout<<r;
	else cout<<n;
	cout<<endl;
}
int main(){
	string a,b;
	int n,c;
	for(cin>>n;n--;){
		cin>>a>>b>>c;
		if(a=="Simon"&&b=="says")fizzbuzz(c);
	}
}
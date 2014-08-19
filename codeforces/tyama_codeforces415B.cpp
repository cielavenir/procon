#include <iostream>
using namespace std;
int main(){
	long long n,a,b,x,y,i;
	cin>>n>>a>>b;
	for(i=0;i<n;i++){
		cin>>x;
		y=x*a/b*b;
		cout<<x-(y+a-1)/a<<(i<n-1?" ":"\n");
	}
}
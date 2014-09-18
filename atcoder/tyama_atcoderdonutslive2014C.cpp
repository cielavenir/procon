#include <iostream>
#include <climits>
using namespace std;
int main(){
	int r=INT_MIN,s=0,n,i=0,x;
	for(cin>>n;n--;){
		cin>>x;
		s+=x;
		if(r<s)r=s;
		if(s<0)s=0;
	}
	cout<<r<<endl;
}
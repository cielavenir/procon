#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	cout<<a.size()<<' '<<b.size()<<endl;
	cout<<a<<b<<endl;
	swap(a[0],b[0]);
	cout<<a<<' '<<b<<endl;
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int n,i,h,m;
	string s;
	cin>>n>>s;
	h=count(s.begin(),s.end()-1,'H');
	m=count(s.begin(),s.end()-1,'M');
	cout<<(n<2?"HM":h>m||(h==m&&s[n-2]-'H')?"H":"M")<<endl;
}
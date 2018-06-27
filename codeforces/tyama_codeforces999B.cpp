#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		if(n%i==0)reverse(s.begin(),s.begin()+i);
	}
	cout<<s<<endl;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string s,m;
	cin>>s;
	m=s;
	int n=s.size();
	for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++){
		swap(s[i],s[j]);
		m=max(m,s);
		swap(s[i],s[j]);
	}
	cout<<m<<endl;
}
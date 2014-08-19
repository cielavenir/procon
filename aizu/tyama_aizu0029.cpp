#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	string s,t,u;
	int M=0,l=0;
	map<string,int>m;
	for(;cin>>u;t=t.size()<u.size()?u:t)if(++m[u]>M)M=m[u],s=u;
	cout<<s<<' '<<t<<endl;
}
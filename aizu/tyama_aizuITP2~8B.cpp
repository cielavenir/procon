#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	int q,a,b;
	string s;
	cin>>q;
	map<string,int>m;
	for(;q--;){
		cin>>a;
		if(a==0)cin>>s>>b,m[s]=b;
		if(a==1)cin>>s,cout<<m[s]<<endl;
		if(a==2)cin>>s,m.erase(s);
	}
}

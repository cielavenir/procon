#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
	int q,a,b;
	string s;
	cin>>q;
	set<string>m;
	for(;q--;){
		cin>>a;
		if(a==0)cin>>s,m.insert(s),cout<<m.size()<<endl;
		if(a==1)cin>>s,cout<<m.count(s)<<endl;
	}
}

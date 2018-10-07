#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	int q,a,b;
	string s,t;
	cin>>q;
	map<string,int>m;
	for(;q--;){
		cin>>a;
		if(a==0)cin>>s>>b,m[s]=b;
		if(a==1)cin>>s,cout<<(m.find(s)==m.end()?0:m.at(s))<<endl;
		if(a==2)cin>>s,m.erase(s);
		if(a==3){cin>>s>>t;auto it1=m.lower_bound(s),it2=m.upper_bound(t);for(;it1!=it2;++it1)cout<<it1->first<<' '<<it1->second<<endl;}
	}
}

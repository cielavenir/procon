#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	int q,a,b;
	string s,t;
	cin>>q;
	multimap<string,int>m;
	for(;q--;){
		cin>>a;
		if(a==0)cin>>s>>b,m.emplace(s,b);
		if(a==1){cin>>s;auto it1=m.lower_bound(s),it2=m.upper_bound(s);for(;it1!=it2;++it1)cout<<it1->second<<endl;}
		if(a==2)cin>>s,m.erase(s);
		if(a==3){cin>>s>>t;auto it1=m.lower_bound(s),it2=m.upper_bound(t);for(;it1!=it2;++it1)cout<<it1->first<<' '<<it1->second<<endl;}
	}
}

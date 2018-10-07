#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
	int q,a,b;
	int s,t;
	cin>>q;
	multiset<int>m;
	for(;q--;){
		cin>>a;
		if(a==0)cin>>s,m.insert(s),cout<<m.size()<<endl;
		if(a==1)cin>>s,cout<<m.count(s)<<endl;
		if(a==2)cin>>s,m.erase(s);
		if(a==3){cin>>s>>t;auto it1=m.lower_bound(s),it2=m.upper_bound(t);for(;it1!=it2;++it1)cout<<*it1<<endl;}
	}
}

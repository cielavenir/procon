#include <iostream>
#include <set>
using namespace std;
typedef set<long long> sll;
main(){
	int n,k,r=0;
	long long x;
	cin>>n>>k;
	sll se;
	for(;n--;){
		cin>>x;
		se.insert(x);
	}
	sll::iterator it=se.begin();
	pair<sll::iterator,sll::iterator> range;
	for(;it!=se.end();it++){
		range=se.equal_range(*it-k);
		r+=(int)distance(range.first,range.second);
		range=se.equal_range(k-*it);
		r+=(int)distance(range.first,range.second);
	}
	cout<<r<<endl;
}
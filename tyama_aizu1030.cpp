#include <iostream>
#include <string>
#include <map>
#include <tuple>
using namespace std;
main(){
	int i,n,h,a,b;
	string s;
	for(;cin>>n>>h,n;){
		map<tuple<int,int,int>,int>m;
		for(;h;h--)for(cin>>s>>a>>b,i=1;i<=n;i++){
			if(s=="xy")m[make_tuple(a,b,i)]=1;
			if(s=="yz")m[make_tuple(i,a,b)]=1;
			if(s=="xz")m[make_tuple(a,i,b)]=1;
		}
		cout<<n*n*n-m.size()<<endl;
	}
}
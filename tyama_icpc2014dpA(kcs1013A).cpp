#include <iostream>
#include <string>
#include <set>
using namespace std;
const set<set<string>> correct={
	{"lu","ru"},{"ld","rd"}
};
int main(){
	int n,i,r;
	string x,y;
	for(;cin>>n,n;cout<<r<<endl){
		for(r=i=0;i<n/2;i++){
			set<string>se;
			cin>>x>>y;
			se.insert(x);
			se.insert(y);
			if(correct.find(se)!=correct.end())r++;
		}
		if(n&1)cin>>x;
	}
}
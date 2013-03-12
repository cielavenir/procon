#include <iostream>
#include <string>
#include <queue>
using namespace std;
main(){
	queue<pair<string,int> >v;
	int N,Q,T;
	string s;
	for(cin>>N>>Q;N--;)cin>>s>>T,v.push(make_pair(s,T));
	for(T=0;!v.empty();){
		pair<string,int>p=v.front();v.pop();
		if(p.second>Q)T+=Q,p.second-=Q,v.push(p);
		else T+=p.second,cout<<p.first<<' '<<T<<endl;
	}
}
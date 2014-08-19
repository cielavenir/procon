#include <queue>
#include <string>
#include <iostream>
using namespace std;
main(){
	priority_queue<int>q;
	string s;
	int k;
	for(;cin>>s&&s!="end";){
		if(s=="insert"){
			cin>>k;
			q.push(k);
		}else
			cout<<q.top()<<endl,q.pop();
	}
}
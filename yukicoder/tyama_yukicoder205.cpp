#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main(){
	priority_queue<string,vector<string>,greater<string> >q;
	int N;
	for(cin>>N;N--;){
		string s;
		cin>>s;
		q.push(s+'~');
	}
	string t;
	for(;!q.empty();){
		string s=q.top();q.pop();
		t+=s[0];
		if(s.size()>2)q.push(s.substr(1));
	}
	cout<<t<<endl;
}
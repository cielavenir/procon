#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

string replace_all(const string &str,const string &from,const string &to){
	string r;
	for(int i=0;i<str.size();){
		if(str.substr(i,from.size())==from)r+=to,i+=from.size();
		else r+=str[i++];
	}
	return r;
}

int main(){
	int n;
	for(;cin>>n,n;){
		vector<pair<string,string> >v(n);
		for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;
		string start,goal;
		cin>>start>>goal;
		queue<string>q;
		q.push(start);
		map<string,int>m;
		m[start]=0;
		for(q.push(start);!q.empty();){
			for(int i=0;i<v.size();i++){
				string nxt=replace_all(q.front(),v[i].first,v[i].second);
				if(nxt.size()<=goal.size() && m.find(nxt)==m.end()){
					q.push(nxt);
					m[nxt]=m[q.front()]+1;
				}
				if(nxt==goal){
					cout<<m[nxt]<<endl;
					goto NEXT;
				}
			}
			q.pop();
		}
		cout<<-1<<endl;
		NEXT:;
	}
}
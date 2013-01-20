#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;
bool diff1(string &s,string &t){
	int r=0,i=0;
	for(;i<s.length();i++){
		r+=s[i]!=t[i];
		if(r>1)return false;
	}
	return true;
}
int main(){
	string f,l,z;
	vector<string>a;
	int n,i=0;
	cin>>f>>l>>n;
	for(i=0;i<n;i++)cin>>z,a.push_back(z);
	if(f==l){cout<<0<<endl;cout<<f<<endl;cout<<l<<endl;return 0;}
	map<string,string>h_prev;
	h_prev[f]="";
	queue<pair<string,int> >q;
	for(q.push(make_pair(f,0));!q.empty();){
		pair<string,int> x=q.front();q.pop();
		if(diff1(x.first,l)){
			q.push(make_pair(l,x.second+1));
			h_prev[l]=x.first;
			break;
		}
		for(i=0;i<n;i++)if(h_prev.find(a[i])==h_prev.end()&&diff1(x.first,a[i])){
			q.push(make_pair(a[i],x.second+1));
			h_prev[a[i]]=x.first;
		}
	}
	if(q.empty()){cout<<-1<<endl;return 0;}
	vector<string>r;
	r.push_back(l);
	for(z=l;h_prev[z][0];z=h_prev[z])r.push_back(h_prev[z]);
	cout<<(r.size()-2)<<endl;
	for(i=r.size()-1;~i;i--)cout<<r[i]<<endl;
}
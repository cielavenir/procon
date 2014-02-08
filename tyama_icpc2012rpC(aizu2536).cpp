#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
main(){
	int n,m,s,t,c,i;
	for(;cin>>n>>m,n;){
		map<int,vector<P> >E;
		for(i=0;i<m;i++){
			cin>>s>>t>>c;
			E[s].push_back(make_pair(c,t));
			E[t].push_back(make_pair(c,s));
		}
		map<int,int>v;
		vector<int>a;
		priority_queue<P,vector<P>,greater<P> >Q;
		Q.push(make_pair(0,1));
		for(;!Q.empty();){
			P p=Q.top();Q.pop();
			if(!v[p.second]){
				v[p.second]=1;
				a.push_back(p.first);
				for(i=0;i<E[p.second].size();i++)Q.push(make_pair(E[p.second][i].first,E[p.second][i].second));
			}
		}
		sort(a.begin(),a.end());
		cout<<a[n/2]<<endl;
	}
}
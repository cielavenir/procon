#include <vector>
#include <string>
#include <iostream>
using namespace std;
main(){int N,Q,i,x,y;string s;for(;cin>>N>>Q,N;){
	vector<pair<int,pair<int,string> > >v;
	for(i=0;i<N;i++)cin>>s>>x>>y,v.push_back(make_pair(y-x,make_pair(y,s)));
	for(i=0;i<Q;y<N?cout<<v[y].second.second<<' '<<x-v[y].first<<endl:cout<<"Unknown"<<endl,i++)for(cin>>x,y=0;y<N;y++)if(v[y].first<x&&x<=v[y].second.first)break;
}}
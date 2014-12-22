#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
main(){
	int i=0,n,x,m=9999999;
	vector<int>v;
	vector<pair<int,int> >result;
	for(cin>>n;i<n;i++)cin>>x,v.push_back(x);
	sort(v.begin(),v.end());
	for(i=0;i<n-1;i++){
		if(v[i+1]-v[i]<m)m=v[i+1]-v[i],result.clear();
		if(v[i+1]-v[i]==m)result.push_back(make_pair(v[i],v[i+1]));
	}
	for(i=0;i<result.size();i++){
		if(i)cout<<' ';
		cout<<result[i].first<<' '<<result[i].second;
	}
	cout<<endl;
}
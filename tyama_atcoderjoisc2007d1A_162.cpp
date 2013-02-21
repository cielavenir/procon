#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
main(){
	int n,i,s;
	vector<pair<int,int> >v1,v2;
	for(cin>>n,i=0;i<n;i++)cin>>s,v1.push_back(make_pair(-s,i));
	sort(v1.begin(),v1.end());
	v2.push_back(make_pair(v1[0].second,1));
	for(s=0,i=1;i<n;i++){
		if(v1[i-1].first<v1[i].first)s=i;
		v2.push_back(make_pair(v1[i].second,s+1));
	}
	sort(v2.begin(),v2.end());
	for(i=0;i<n;i++)cout<<v2[i].second<<endl;
}
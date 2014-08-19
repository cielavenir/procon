#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;
//chokudai's algorithm 2012/12/03.
main(){
	int N,M,K,j,k,i;
	string s,t;
	vector<string>v;
	map<int,int>tweets,timeline;
	cin>>N>>M>>K;getline(cin,s);
	for(i=0;i<M;i++)getline(cin,s),v.push_back(s);
	for(i--;~i;i--){
		istringstream ss(v[i]);
		ss>>t>>j>>k;
		if(t=="t")tweets[j]++;
		if(t=="f")timeline[j]+=tweets[k],timeline[k]+=tweets[j];
		if(t=="u")timeline[j]-=tweets[k],timeline[k]-=tweets[j];
	}
	map<int,int>::iterator it;
	for(it=tweets.begin();it!=tweets.end();it++)timeline[it->first]+=it->second;
	vector<int>result;
	for(it=timeline.begin();it!=timeline.end();it++)result.push_back(it->second);
	sort(result.begin(),result.end(),greater<int>());
	cout<<(K>result.size()?0:result[K-1])<<endl;
}
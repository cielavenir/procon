#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	int N,K,n;
	cin>>N>>K;
	map<pair<string,string>,int>m;
	for(;N--;){
		cin>>n;
		vector<string>v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
			for(int j=0;j<i;j++){
				auto p=make_pair(v[i],v[j]);
				if(p.first>p.second)swap(p.first,p.second);
				m[p]++;
			}
		}
	}
	vector<pair<string,string>>v;
	for(auto &e:m)if(e.second>=K)v.push_back(e.first);
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(auto &e:v)cout<<e.first<<' '<<e.second<<endl;
}

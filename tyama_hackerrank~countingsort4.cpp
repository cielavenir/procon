#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	vector<pair<pair<int,int>,string> > v;
	int N,i=0,x;string s;
	for(cin>>N;i<N;i++)cin>>x>>s,v.push_back(make_pair(make_pair(x,i),i<N/2?"-":s));
	sort(v.begin(),v.end());
	for(i=0;i<N;i++)cout<<v[i].second<<(i==N-1?"\n":" ");
}
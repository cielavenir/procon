#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

string s;
bool ispalin(int start,int end){
	for(;start<end;start++,end--){
		if(s[start]!=s[end])return false;
	}
	return true;
}	
long long dfs(int d,const vector<int>&v,vector<long long>&memo){
	if(d==s.size())return 0;
	if(memo[d])return memo[d];
	long long ret=1LL<<62;
	for(int i=d;i<s.size();i++)if(ispalin(d,i))ret=min(ret,v[i-d]+dfs(i+1,v,memo));
	return memo[d]=ret;
}	

int main(){
	int N;
	cin>>N>>s;
	vector<int>v(N);
	vector<long long>memo(N);
	for(int i=0;i<N;i++)cin>>v[i];
	printf("%lld\n",dfs(0,v,memo));
}
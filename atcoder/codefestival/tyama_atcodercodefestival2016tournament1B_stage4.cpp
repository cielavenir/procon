#include <iostream>
#include <string>
#include <map>
using namespace std;
string S;
int N,L;

bool myless(const pair<int,int> &x, const pair<int,int> &y){
	if(x.second-x.first<y.second-y.first)return true;
	if(x.second-x.first>y.second-y.first)return false;
	int l=x.second-x.first;
	for(int i=0;i<l;i++){
		if(S[x.first+i]<S[y.first+i])return true;
		if(S[x.first+i]>S[y.first+i])return false;
	}
	return false;
}
map<pair<int,int>,pair<int,int>> memo;
pair<int,int> dfs(int k,int idx){
	auto key=make_pair(k,idx);
	if(memo.find(key)!=memo.end())return memo[key];
	pair<int,int> r={idx,N};
	if(k>0)for(int i=idx+max(1,L-1);i<min(N,idx+L+1);i++){
		r=min(r,max({idx,i},dfs(k-1,i),myless),myless);
	}
	return memo[key]=r;
}
int main(){
	int K;
	cin>>K>>S;
	N=S.size(),L=(S.size()+K)/(K+1);
	if(N>2000)return 1;
	pair<int,int> r=dfs(K,0);
	cout<<S.substr(r.first,r.second-r.first)<<endl;
}

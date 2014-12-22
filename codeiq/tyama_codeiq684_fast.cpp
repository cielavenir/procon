//gemstring fast solution
//based on https://gist.github.com/tatt61880/8958003

#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
#define list     "abbbbcddddeefggg"
#define desired_ "eagcdfbe"

vector<long long>fact;
long long dfs(vector<int>&v,vector<int> &a,int d){
	long long r=0;
	if(d==v.size()){
		for(int i=0;i<a.size();i++)r+=a[i];
		r=fact[r];
		for(int i=0;i<a.size();i++)r/=fact[a[i]];
	}else{
		for(int i=0;i<=v[d];i++){
			a.push_back(i);
			r+=dfs(v,a,d+1);
			a.pop_back();
		}
	}
	return r;
}

int main(){
	vector<int> a;
	vector<int> counts(7); //should not be hard-coded...
	for(int i=0;i<strlen(list);i++)counts[list[i]-'a']++;
	fact.push_back(1);
	for(int i=1;i<strlen(list);i++)fact.push_back(fact[i-1]*i);
	vector<int> desired(strlen(desired_));
	for(int i=0;i<strlen(desired_);i++)desired[i]=desired_[i]-'a';

	long long r=0;
	for(int n=0;n<strlen(desired_);n++){
		r++;
		for(int i=0;i<desired[n];i++){
			counts[i]--;
			r+=dfs(counts,a,0);
			counts[i]++;
		}
		counts[desired[n]]--;
	}
	printf("%lld\n",r);
}

/*
naive:
Ruby unknown
C#   unknown
C    21s
fast:
Ruby 0.22s
C++  0.01s
*/
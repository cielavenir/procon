#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
vector<int>res;
int ma,cnt;

void dfs(int s,const int t,const string n,vector<int>&v){
	if(s>t)return;
	if(n.empty()){
		if(ma<s)ma=s,cnt=0;
		if(ma==s)res=v,cnt++;
	}else{
		int add=0;
		for(int i=0;i<n.size();i++){
			add=add*10+n[i]-'0';
			v.push_back(add);
			dfs(s+add,t,n.substr(i+1),v);
			v.pop_back();
		}
	}
}

int main(){
	int t;
	string n;
	for(;cin>>t>>n,t;){
		vector<int>v;
		ma=0,cnt=0;
		dfs(0,t,n,v);
		if(cnt>1)puts("rejected");
		else if(!ma)puts("error");
		else{
			printf("%d",ma);
			for(int i=0;i<res.size();i++)printf(" %d",res[i]);
			puts("");
		}
	}
}
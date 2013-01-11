#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

map<int,vector<pair<string,int> > >m;
char ans[10000],rans[10000];
int memo[50],g;

int dfs(int p){
	int f=0,r,c=0;
	char *a=ans+strlen(ans);
	memo[p]=1;
	vector<pair<string,int> >v=m[p];
	if(v.empty())return -1;
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		//cout<<"---"<<v[i].first<<memo[v[i].second]<<endl;
		if(memo[v[i].second]){f=1;continue;}
		strcpy(a,v[i].first.c_str());
		if(v[i].second==g){
			if(f)return -2;
			else{strcpy(rans,ans);memo[p]=0;return 0;}
		}
		if(*rans&&strcmp(rans,ans)<0){memo[p]=0;return 0;}
		r=dfs(v[i].second);
		if(r==0){
			if(f)return -2;
			c=1;
			//else return 0;
		}
		if(r==-2)return -2;
	}
	memo[p]=0;
	return c?0:-1;
}

int main(){
	int n,a,s;
	for(;cin>>n>>a>>s>>g,n;){
		m.clear();
		*ans=0;*rans=0;memset(memo,0,sizeof(memo));
		int _a,_b;string _s;
		for(;a;a--)cin>>_a>>_b>>_s,m[_a].push_back(make_pair(_s,_b));
		_a=dfs(s);
		if(_a<0)puts("NO");else puts(rans);
	}
}
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char s[999];
int N;
map<int,vector<int> >m;
set<int>se;
set<pair<char*,int>>memo;
void dfs(char *p, int cur){
	if(memo.find(make_pair(p,cur))!=memo.end())return;
	char *q=p;
	for(;*q=='w';)q++;
	int attack=q!=p;
	vector<int> &v=m[cur];
	//printf("+++%s,%d\n",p,cur);
	if(!*q){
		if(attack){
			int i=0;
			for(;i<v.size();i++)se.insert(v[i]);
		}else{
			int i=1;
			for(;i<=N;i++)if(find(v.begin(),v.end(),i)==v.end())se.insert(i);
		}
		return;
	}
	if(*q=='"')q++;
	int ret=0;
	if(attack){	
		int i=0;
		for(;i<v.size();i++)dfs(q,v[i]);
	}else{
		int i=1;
		for(;i<=N;i++)if(find(v.begin(),v.end(),i)==v.end())dfs(q,i);
	}
	memo.insert(make_pair(p,cur));
}

int main(){
	int M,i,a,b,c;
	scanf("%d%d",&N,&M);
	for(i=0;i<M;i++){
		scanf("%d%d",&a,&b);
		m[b].push_back(a);
	}
	scanf("%s",s);
	char *p=strstr(s,"group")+5;
	c=strtol(p,NULL,10);
	for(;'0'<=*p&&*p<='9';)p++;
	dfs(p,c);
	printf("%d\n",se.size());
}

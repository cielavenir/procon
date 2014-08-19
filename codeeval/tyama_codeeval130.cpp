#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

string A,S;
map<int,bool>m;
bool dfs(int a,int s){
	bool ba=a==A.size();
	bool bs=s==S.size();
	if(bs)return ba;
	int x=(a<<16)|s;
	if(m.find(x)!=m.end())return m[x];
	if(S[s-1]==S[s]&&dfs(a,s+1))return m[x]=true;
	if(ba)return m[x]=false;

	if((A[a]!='0'||S[s]=='A')&&dfs(a+1,s+1))return m[x]=true;
	return m[x]=false;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	for(;cin>>A>>S;){
		if(A[0]=='0'&&S[0]=='B')puts("No");
		else m.clear(),puts(dfs(1,1)?"Yes":"No");
	}
}
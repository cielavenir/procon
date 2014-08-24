#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
string s;
vector<string> t;
map<int,long long>m;
long long dfs(int idx){
	if(idx==s.size())return 1;
	if(m.find(idx)!=m.end())return m[idx];
	long long result=0;
	for(int i=0;i<t.size();i++){
		if(t[i].size()<=s.size()-idx){
			int j=0;
			for(;j<t[i].size();j++)if(t[i][j]!=s[idx+j])break;
			if(j==t[i].size())result+=dfs(idx+t[i].size());
		}
	}
	return m[idx]=result%1000000007;
}

int main(){
	int n;
	cin>>n>>s;
	t.resize(n);
	for(int i=0;i<n;i++)cin>>t[i];
	cout<<dfs(0)<<endl;
}
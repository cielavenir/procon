#include <string>
#include <vector>
#include <set>
#include <cstdio>
#include <cstdlib>
using namespace std;
set<pair<int,int> >se;
void dfs(int total,int cur,vector<int> &v,string s){
	if(s.size()==v.size()-1){
		if(cur==total){
			puts(s.c_str());
			exit(0);
		}
		return;
	}
	if(cur>total||se.find(make_pair(cur,s.size()))!=se.end())return;
	dfs(total,cur+v[s.size()+1],v,s+'+');
	dfs(total,cur*v[s.size()+1],v,s+'*');
	se.insert(make_pair(cur,s.size()));
}

int main(){
	int n,total;
	scanf("%d%d",&n,&total);
	vector<int>v(n);
	for(int i=0;i<n;i++)scanf("%d",&v[i]);
	dfs(total,v[0],v,"");
}
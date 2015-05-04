#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <algorithm>
using namespace std;
//#define FLOAT

void dfs(int id,int depth,map<int,string>&id2name,map<int,deque<int> >&children){
	cout<<string(depth,'.')<<id2name[id]<<endl;
	for(int i=0;i<children[id].size();i++){
		dfs(children[id][i],depth+1,id2name,children);
	}
}

int main(){
	map<int,string>id2name;
	map<int,int>parent;
	map<int,deque<int> >children;

	int N,k;
	string s;
	cin>>N;
	cin>>k>>s;
	parent[1]=0;
	id2name[1]=s;
#ifdef FLOAT
	children[k].push_front(1);
#else
	children[k].push_back(1);
#endif
	for(int post=2;post<=N;post++){
		cin>>k>>s;
		parent[post]=k;
		id2name[post]=s;
		for(int cur=post;cur;cur=parent[cur]){
			children[parent[cur]].erase(remove(children[parent[cur]].begin(),children[parent[cur]].end(),cur),children[parent[cur]].end());
#ifdef FLOAT
			children[parent[cur]].push_front(cur);
#else
			children[parent[cur]].push_back(cur);
			break;
#endif
		}
	}
	dfs(1,0,id2name,children);
}
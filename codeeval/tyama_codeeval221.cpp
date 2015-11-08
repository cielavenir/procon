#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <set>
#include <cstdio>
using namespace std;

void dfs(char cur,unordered_map<char,set<char> >&children){
	bool first=true;
	putchar(cur);
	for(auto &e:children[cur]){
		if(first)printf(" [");
		else printf(", ");
		first=false;
		dfs(e,children);
	}
	if(!first)printf("]");
}

int main(){
	string line,s;
	for(;getline(cin,line);){
		unordered_map<char,set<char> >children;
		unordered_map<char,char>parent;
		istringstream ss(line);
		for(;ss>>s;ss>>s){
			parent[s[1]]=s[0];
			children[s[0]].insert(s[1]);
		}
		char root;
		for(auto &e:children)if(parent.find(e.first)==parent.end()){
			root=e.first;
			break;
		}
		dfs(root,children);
		puts("");
	}
}
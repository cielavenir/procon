//Note: this still fails in some test cases.

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str);
	}
	return result;
}
vector<int> split_int(string str, const char *delim){
	vector<int> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(strtol(str.substr(0, cutAt).c_str(),NULL,10));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(strtol(str.c_str(),NULL,10));
	}
	return result;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int i,j,m;
	string line;
	for(;getline(cin,line);){
		map<int,vector<pair<int,int> > >edges;
		int start,goal;
		map<int,int>depth;
		queue<int>q;
		vector<int>goals;
		{
			map<int,vector<int> >transfer;
			vector<vector<int> >v;
			vector<string>A=split(line,";");
			vector<int>a=split_int(A[0].substr(1),",");
			start=a[0],goal=a[1];
			for(i=1;i<A.size();i++){
				vector<string>b=split(A[i],"=");
				vector<int>c=split_int(b[1].substr(1),",");
				for(j=0;j<c.size();j++){
					if(j<c.size()-1){
						edges[(i<<16)+c[j]].push_back(make_pair((i<<16)+c[j+1],7));
						edges[(i<<16)+c[j+1]].push_back(make_pair((i<<16)+c[j],7));
					}
					transfer[c[j]].push_back((i<<16)+c[j]);
					if(c[j]==start)q.push((i<<16)+c[j]),depth[(i<<16)+c[j]]=0;
					if(c[j]==goal)goals.push_back((i<<16)+c[j]);
				}
			}
			for(auto it=transfer.begin();it!=transfer.end();++it){
				for(i=0;i<it->second.size()-1;i++)
					for(j=i+1;j<it->second.size();j++){
						edges[it->second[i]].push_back(make_pair(it->second[j],12));
						edges[it->second[j]].push_back(make_pair(it->second[i],12));
					}
			}
		}
		for(;!q.empty();){
			int n=q.front();
			q.pop();
			for(i=0;i<edges[n].size();i++){
				if(depth.find(edges[n][i].first)==depth.end() || depth[edges[n][i].first]>depth[n]+edges[n][i].second){
					//printf("%d %d %d\n",n,edges[n][i].first,depth[n]+edges[n][i].second);
					depth[edges[n][i].first]=depth[n]+edges[n][i].second;
					q.push(edges[n][i].first);
				}
			}
		}
		m=1<<30;
		for(i=0;i<goals.size();i++)if(depth.find(goals[i])!=depth.end()&&depth[goals[i]]<m)m=depth[goals[i]];
		if(m==1<<30)puts("None");
		else printf("%d\n",m);
	}
}
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

vector<vector<int> >result;
void dfs(int l,int cur,int goal,vector<int>&r,vector<int> &dist,vector<vector<int> >&back){
	if(cur==goal)result.push_back(r);
	else if(r.size()<l)for(int i=0;i<back[cur].size();i++){
		int b=back[cur][i];
		r.push_back(b);
		dfs(l,b,goal,r,dist,back);
		r.pop_back();
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<vector<unsigned int> >v;
	map<unsigned int,vector<int> >conn;
	int start,goal;
	int N,i,j,k;
	{
		string line;
		getline(cin,line);
		vector<string> a=split(line,"]");
		a.pop_back();
		N=a.size();
		a[0]=a[0].substr(1);
		for(i=1;i<N;i++)a[i]=a[i].substr(2);
		v.resize(N);
		for(j=0;j<N;j++){
			vector<string> b=split(a[j],"[");
			int host=strtol(b[0].c_str(),NULL,10);
			if(b.size()<2)continue;
			vector<string> c=split(b[1],",");
			c[0]=c[0].substr(1);
			for(i=1;i<c.size();i++)c[i]=c[i].substr(2);
			for(i=0;i<c.size();i++){
				vector<string> d=split(c[i],"/");
				unsigned int mask=~((1<<(32-strtol(d[1].c_str(),NULL,10)))-1);
				vector<string> e=split(d[0],".");
				unsigned int ipaddress=(
					(strtol(e[0].c_str(),NULL,10)<<24)|
					(strtol(e[1].c_str(),NULL,10)<<16)|
					(strtol(e[2].c_str(),NULL,10)<<8)|
					(strtol(e[3].c_str(),NULL,10)<<0)
				)&mask;
				v[host].push_back(ipaddress);
				conn[ipaddress].push_back(host);
			}
		}
	}
	for(;cin>>goal>>start;){
		if(goal<0||N<=goal||start<0||N<=start){puts("No connection");continue;}
		vector<int> dist(N);
		vector<vector<int> > back(N);
		queue<pair<int,int> >q;
		q.push(make_pair(start,1));
		for(;!q.empty();){
			pair<int,int> _cur=q.front();
			int cur=_cur.first,depth=_cur.second;
			if(cur==goal)break;
			q.pop();
			for(i=0;i<v[cur].size();i++)
				for(j=0;j<conn[v[cur][i]].size();j++)
					if(!dist[conn[v[cur][i]][j]]||dist[conn[v[cur][i]][j]]==depth+1){
						dist[conn[v[cur][i]][j]]=depth+1;
						back[conn[v[cur][i]][j]].push_back(cur);
						q.push(make_pair(conn[v[cur][i]][j],depth+1));
					}
		}
		if(q.empty())puts("No connection");
		else{
			for(i=0;i<N;i++){
				sort(back[i].begin(),back[i].end());
				back[i].erase(unique(back[i].begin(),back[i].end()),back[i].end());
			}
			vector<int>r;
			r.push_back(goal);
			dfs(dist[goal],goal,start,r,dist,back);
			for(i=0;i<result.size();i++){
				if(i)printf(", ");
				printf("[");
				for(j=0;j<result[i].size();j++){
					if(j)printf(", ");
					printf("%d",result[i][j]);
				}
				result[i].clear();
				printf("]");
			}
			puts("");
			result.clear();
		}
	}
}
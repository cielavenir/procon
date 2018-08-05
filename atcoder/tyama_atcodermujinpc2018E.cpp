#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

const map<char,pair<int,int>>D={
	{'L',{-1,0}},
	{'D',{0,1}},
	{'R',{1,0}},
	{'U',{0,-1}},
};

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	string d;
	cin>>d;
	pair<int,int> st,go;
	vector<string>s(n);
	for(int i=0;i<n;i++){
		cin>>s[i];
		int j=s[i].find_first_of('S');
		if(j>=0)st={i,j};
		j=s[i].find_first_of('G');
		if(j>=0)go={i,j};
	}
	//calculate cost table
	vector<map<char,int>> costs(k);
	for(int i_=0;i_<k;i_++){
		int i=i_;
		int o=i;
		int z=0;
		costs[i][d[o]]=z;
		i-=1;if(i==-1)i=k-1;
		z++;
		for(;d[o]!=d[i];){
			costs[i][d[o]]=z;
			i-=1;if(i==-1)i=k-1;
			z++;
		}
	}
	//bfs
	map<pair<int,int>,long long>depth;
	priority_queue<pair<long long,pair<int,int>>>q;
	q.push({0,st});
	for(;!q.empty();){
		long long curcost;
		pair<int,int> cur;
		tie(curcost,cur)=q.top();q.pop();
		curcost=-curcost;
		if(depth.find(cur)!=depth.end())continue;
		depth[cur]=curcost;
		if(cur==go){
			cout<<curcost<<endl;
			return 0;
		}
		for(auto &e:D){
			char _d=e.first;int dx=e.second.first,dy=e.second.second;
			if(costs[curcost%k].find(_d)==costs[curcost%k].end())continue;
			long long ncost=costs[curcost%k][_d]+curcost+1;
			int nx=cur.second+dx;
			int ny=cur.first+dy;
			if(0<=nx&&nx<m && 0<=ny&&ny<n && s[ny][nx]!='#'){
				q.push({-ncost,{ny,nx}});
			}
		}
	}
	cout<<-1<<endl;
}

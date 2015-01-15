#include <map>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
vector<int>start={1,2,3,4,5,6,7,8,9,10,11,12,13,14};
vector<int>goal={7,12,9,3,4,8,2,1,5,10,13,11,6,14};

void output(vector<int> &v){
	for(int x=0;x<v.size();x++){
		printf(x<v.size()-1?"%d ":"%d\n",v[x]);
	}
}
void backtrack(map<vector<int>,vector<int>> &m, vector<int> &v){
	if(m[v]!=v)backtrack(m,m[v]);
	output(v);
}
void forwardtrack(map<vector<int>,vector<int>> &m, vector<int> &v){
	output(v);
	if(m[v]!=v)forwardtrack(m,m[v]);
}
int main(){
	queue<pair<vector<int>,bool>>q;
	map<vector<int>,vector<int>>mstart;
	map<vector<int>,vector<int>>mgoal;
	q.push(make_pair(start,false));
	q.push(make_pair(goal,true));
	mstart[start]=start;
	mgoal[goal]=goal;
	for(;!q.empty();){
		pair<vector<int>,bool>_prev=q.front();q.pop();
		vector<int>prev=_prev.first;bool f=_prev.second;
		vector<int>v=prev;
		map<vector<int>,vector<int>>&m=f?mgoal:mstart;
		map<vector<int>,vector<int>>&m2=f?mstart:mgoal;
		for(int i=0;i<v.size()-1;i++){ //始点
			for(int j=i+2;j<=v.size();j++){ //終点
				rotate(v.begin()+i,v.begin()+i+1,v.begin()+j);
				if(m.find(v)==m.end()){
					q.push(make_pair(v,f));
					m[v]=prev;
					if(m2.find(v)!=m2.end()){
						backtrack(mstart,v);
						forwardtrack(mgoal,mgoal[v]);
						return 0;
					}
				}
				rotate(v.begin()+i,v.begin()+j-1,v.begin()+j);
				rotate(v.begin()+i,v.begin()+j-1,v.begin()+j);
				if(m.find(v)==m.end()){
					q.push(make_pair(v,f));
					m[v]=prev;
					if(m2.find(v)!=m2.end()){
						backtrack(mstart,v);
						forwardtrack(mgoal,mgoal[v]);
						return 0;
					}
				}
				rotate(v.begin()+i,v.begin()+i+1,v.begin()+j);
			}
		}
	}
}
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14
1 2 9 3 4 5 6 7 8 10 11 12 13 14
1 2 9 3 4 6 7 8 5 10 11 12 13 14
1 2 9 3 4 7 8 5 10 11 12 13 6 14
1 2 9 3 4 7 8 5 10 12 13 11 6 14
1 2 12 9 3 4 7 8 5 10 13 11 6 14
2 12 9 3 4 7 8 1 5 10 13 11 6 14
12 9 3 4 7 8 2 1 5 10 13 11 6 14
7 12 9 3 4 8 2 1 5 10 13 11 6 14

real	1m38.945s
user	1m24.088s
sys	0m8.865s
*/
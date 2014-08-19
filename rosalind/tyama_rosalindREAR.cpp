//-O2 is required.
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef vector<int> V;
map<V,int>m;
//map<V,pair<pair<int,int>,V> >track;
//V v1,v2;
pair<int,int>vec2nvec;
int bfs(V &v, int back){
	if(!back&&m.find(v)!=m.end()){
		//v1.clear();
		//vec2nvec=make_pair(0,0);
		//v2=v;
		return m[v];
	}
	set<V>s;
	queue<pair<V,int> >q;
	if(back)m[v]=0;
	s.insert(v);
	int i,j;
	for(q.push(make_pair(v,0));!q.empty();){
		V vec=q.front().first;
		int depth=q.front().second;
		q.pop();
		if(back&&depth>3)return 0;
		for(i=0;i<vec.size();i++)
			for(j=i+1;j<vec.size();j++){
				V nvec=vec;
				reverse(nvec.begin()+i,nvec.begin()+j+1);
				if(!back&&m.find(nvec)!=m.end()){
					//v1=vec;
					//vec2nvec=make_pair(i,j);
					//v2=nvec;
					return depth+1+m[nvec];
				}
				if(!s.insert(nvec).second)continue;
				if(back)m[nvec]=depth+1;
				//track[nvec]=make_pair(make_pair(i,j),vec);
				q.push(make_pair(nvec,depth+1));
			}
	}
	return 0;
}
//void backtrack(V &v){
//	if(track.find(v)==track.end())return;
//	backtrack(track[v].second);
//	printf("%d %d\n",track[v].first.first+1,track[v].first.second+1);
//}
//void forwardtrack(V &v){
//	if(track.find(v)==track.end())return;
//	printf("%d %d\n",track[v].first.first+1,track[v].first.second+1);
//	forwardtrack(track[v].second);
//}
int main(){int T=0;for(;;T++){
	m.clear();
	V prob;
	int i=0,t;
	for(;i<10;i++){
		if(scanf("%d",&t)==-1){putchar('\n');return 0;}
		prob.push_back(t);
	}
	V goal;
	for(i=0;i<10;i++){
		scanf("%d",&t);
		goal.push_back(t);
	}
	bfs(goal,1);
	if(T)putchar(' ');
	printf("%d",bfs(prob,0));
	//backtrack(v1);
	//if(vec2nvec.first!=vec2nvec.second)printf("%d %d\n",vec2nvec.first+1,vec2nvec.second+1);
	//forwardtrack(v2);
}}
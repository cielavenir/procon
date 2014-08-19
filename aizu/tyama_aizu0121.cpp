#include <vector>
#include <queue>
#include <map>
#include <cstdio>
using namespace std;
#define X 4
#define Y 2
main(){
	int i=0,t;
	map<vector<int>,pair<int,int> >m;
	queue<vector<int> >q;
	vector<int>v;
	for(;i<X*Y;i++)v.push_back(i);
	m[v]=make_pair(0,0);
	for(q.push(v);!q.empty();){
		v=q.front();q.pop();
		int coor=m[v].first,x=coor%X,y=coor/X;
		int depth=m[v].second;
		if(0<x){
			swap(v[coor],v[coor-1]);
			if(m.find(v)==m.end())m[v]=make_pair(coor-1,depth+1),q.push(v);
			swap(v[coor],v[coor-1]);
		}
		if(x<X-1){
			swap(v[coor],v[coor+1]);
			if(m.find(v)==m.end())m[v]=make_pair(coor+1,depth+1),q.push(v);
			swap(v[coor],v[coor+1]);
		}
		if(0<y){
			swap(v[coor],v[coor-X]);
			if(m.find(v)==m.end())m[v]=make_pair(coor-X,depth+1),q.push(v);
			swap(v[coor],v[coor-X]);
		}
		if(y<Y-1){
			swap(v[coor],v[coor+X]);
			if(m.find(v)==m.end())m[v]=make_pair(coor+X,depth+1),q.push(v);
			swap(v[coor],v[coor+X]);
		}
	}
	v.clear();
	for(i=0;~scanf("%d",&t);){
		v.push_back(t);
		if(++i==X*Y){
			printf("%d\n",m[v].second);
			v.clear();i=0;
		}
	}
}
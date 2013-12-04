//derived from aizu0121
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
using namespace std;
int main(){
	int X,i,j,t;
	vector<int>problem;
	scanf("%d",&X);
	for(i=0;i<X*X;i++)scanf("%d",&t),problem.push_back(t);

	int Y=X;
	map<vector<int>,pair<int,int> >m;
	map<vector<int>,pair<vector<int>,string> >prev;
	queue<vector<int> >q;
	vector<int>v,next;
	for(i=0;i<X*Y;i++)v.push_back(i);
	m[v]=make_pair(0,0);
	prev[v]=make_pair(v,"");
	for(q.push(v);!q.empty();){
		v=q.front();q.pop();
		int coor=m[v].first,x=coor%X,y=coor/X;
		int depth=m[v].second;
		next=v;
		if(0<x){
			swap(v[coor],v[coor-1]);
			if(m.find(v)==m.end())m[v]=make_pair(coor-1,depth+1),q.push(v),prev[v]=make_pair(next,"RIGHT");
			swap(v[coor],v[coor-1]);
		}
		if(x<X-1){
			swap(v[coor],v[coor+1]);
			if(m.find(v)==m.end())m[v]=make_pair(coor+1,depth+1),q.push(v),prev[v]=make_pair(next,"LEFT");
			swap(v[coor],v[coor+1]);
		}
		if(0<y){
			swap(v[coor],v[coor-X]);
			if(m.find(v)==m.end())m[v]=make_pair(coor-X,depth+1),q.push(v),prev[v]=make_pair(next,"DOWN");
			swap(v[coor],v[coor-X]);
		}
		if(y<Y-1){
			swap(v[coor],v[coor+X]);
			if(m.find(v)==m.end())m[v]=make_pair(coor+X,depth+1),q.push(v),prev[v]=make_pair(next,"UP");
			swap(v[coor],v[coor+X]);
		}
		if(m.find(problem)!=m.end())break;
	}

	printf("%d\n",m[problem].second);
	for(;prev[problem].first!=problem;){
		puts(prev[problem].second.c_str());
		problem=prev[problem].first;
	}
}
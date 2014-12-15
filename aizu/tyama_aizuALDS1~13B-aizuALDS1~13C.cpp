#include <vector>
#include <queue>
#include <map>
#include <cstdio>
using namespace std;
#define X 3
#define Y 3
int main(){
	int i=1,start_point;
	vector<int>start(X*Y),goal;
	for(;i<X*Y;i++)goal.push_back(i);goal.push_back(0);
	for(i=0;i<X*Y;i++){
		scanf("%d",&start[i]);
		if(start[i]==0)start_point=i;
	}
	if(start==goal){puts("0");return 0;}

	map<vector<int>,pair<int,int> >mstart,mgoal;
	queue<pair<vector<int>,bool> >q;
	mstart[start]=make_pair(start_point,0);
	mgoal[goal]=make_pair(X*Y-1,0);
	q.push(make_pair(start,false));
	q.push(make_pair(goal,true));
	for(;!q.empty();){
		vector<int> v=q.front().first;
		bool f=q.front().second;
		q.pop();
		map<vector<int>,pair<int,int> >&m=f?mgoal:mstart;
		map<vector<int>,pair<int,int> >&m2=f?mstart:mgoal;
		int coor=m[v].first,x=coor%X,y=coor/X;
		int depth=m[v].second;
		if(0<x){
			swap(v[coor],v[coor-1]);
			if(m.find(v)==m.end())m[v]=make_pair(coor-1,depth+1),q.push(make_pair(v,f));
			if(m2.find(v)!=m2.end()){printf("%d\n",m2[v].second+depth+1);return 0;}
			swap(v[coor],v[coor-1]);
		}
		if(x<X-1){
			swap(v[coor],v[coor+1]);
			if(m.find(v)==m.end())m[v]=make_pair(coor+1,depth+1),q.push(make_pair(v,f));
			if(m2.find(v)!=m2.end()){printf("%d\n",m2[v].second+depth+1);return 0;}
			swap(v[coor],v[coor+1]);
		}
		if(0<y){
			swap(v[coor],v[coor-X]);
			if(m.find(v)==m.end())m[v]=make_pair(coor-X,depth+1),q.push(make_pair(v,f));
			if(m2.find(v)!=m2.end()){printf("%d\n",m2[v].second+depth+1);return 0;}
			swap(v[coor],v[coor-X]);
		}
		if(y<Y-1){
			swap(v[coor],v[coor+X]);
			if(m.find(v)==m.end())m[v]=make_pair(coor+X,depth+1),q.push(make_pair(v,f));
			if(m2.find(v)!=m2.end()){printf("%d\n",m2[v].second+depth+1);return 0;}
			swap(v[coor],v[coor+X]);
		}
	}
}
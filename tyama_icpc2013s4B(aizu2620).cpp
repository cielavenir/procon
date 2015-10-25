#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 99999999

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef unordered_map<int,Edges> Graph;

void shortestPath(Graph &g, int s,
    unordered_map<int,Weight> &dist, unordered_map<int,int> &prev) {
  for(auto &f:g)dist[f.first]=INF; dist[s] = 0;
  priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
  for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
    Edge e = Q.top(); Q.pop();
    if (prev.find(e.dst) != prev.end()) continue;
    prev[e.dst] = e.src;
    for(auto &f:g[e.dst]) {
      if (dist[f.dst] > e.weight+f.weight) {
        dist[f.dst] = e.weight+f.weight;
        Q.push(Edge(f.src, f.dst, e.weight+f.weight));
      }
    }
  }
}

char buf[1001];
int W;
int coor(int x,int y){return (y)*(W+2)+x;}
int main(){
	int H,N,X1,Y1,X2,Y2;
	scanf("%d%d%d%d%d%d%d",&W,&H,&N,&X1,&Y1,&X2,&Y2);
	H*=2,W*=2;
	X1=coor(X1*2,Y1*2),X2=coor(X2*2,Y2*2);
	vector<vector<int> >m(H+1);
	for(auto &&e:m)e.resize(W+1);
	for(int i=0;i<N;i++){
		int x,y,t,l;
		scanf("%d%d%d%s",&x,&y,&t,buf);
		l=strlen(buf);
		x=2*x+1,y=2*y+1;
		for(int j=0;j<t;j++){
			for(int k=0;k<l;k++){
				int c=buf[k];
				if(c=='L'&&1<x)m[y][x-1]++,x-=2;
				if(c=='U'&&1<y)m[y-1][x]++,y-=2;
				if(c=='R'&&x<W-1)m[y][x+1]++,x+=2;
				if(c=='D'&&y<H-1)m[y+1][x]++,y+=2;
			}
		}
	}
	Graph g;
	for(int h=0;h<=H;h+=2)for(int w=0;w<=W;w+=2){
		int a=coor(w,h),b;
		if(h<H)b=coor(w,h+2),g[a].push_back(Edge(a,b,m[h+1][w])),g[b].push_back(Edge(b,a,m[h+1][w]));
		if(w<W)b=coor(w+2,h),g[a].push_back(Edge(a,b,m[h][w+1])),g[b].push_back(Edge(b,a,m[h][w+1]));
	}
	unordered_map<int,Weight> dist;
	unordered_map<int,int> prev;
	shortestPath(g,X1,dist,prev);
	printf("%d\n",dist[X2]);
}
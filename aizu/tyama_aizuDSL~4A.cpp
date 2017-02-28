#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;
long long solve(const vector<pair<pair<int,int>,pair<int,int>>> &v){
	set<int>lx,ly;
	for(auto &e:v){
		lx.insert(e.first.first);lx.insert(e.second.first);
		ly.insert(e.first.second);ly.insert(e.second.second);
	}
	int i;
	map<int,int>mx,my,sx,sy;
	i=0;for(auto ix1=lx.begin(),ix2=lx.begin();++ix2!=lx.end();++ix1,++i){
		mx[*ix1]=i,sx[i]=*ix2-*ix1;
	}
	mx[*lx.rbegin()]=i,sx[i]=0;
	i=0;for(auto iy1=ly.begin(),iy2=ly.begin();++iy2!=ly.end();++iy1,++i){
		my[*iy1]=i,sy[i]=*iy2-*iy1;
	}
	my[*ly.rbegin()]=i,sy[i]=0;
	vector<vector<int>>m(my.size());
	for(auto &e:m)e.resize(mx.size());
#if 0
	for(auto &e:v){
		for(int y=my[e.first.second];y<my[e.second.second];y++)
			for(int x=mx[e.first.first];x<mx[e.second.first];x++)m[y][x]++;
	}
#else
	for(auto &e:v){
		m[my[e.first.second]][mx[e.first.first]]++;
		m[my[e.second.second]][mx[e.first.first]]--;
		m[my[e.first.second]][mx[e.second.first]]--;
		m[my[e.second.second]][mx[e.second.first]]++;
	}
	for(int y=0;y<sy.size();y++)for(int x=1;x<sx.size();x++)m[y][x]+=m[y][x-1];
	for(int y=1;y<sy.size();y++)for(int x=0;x<sx.size();x++)m[y][x]+=m[y-1][x];
#endif
	long long r=0;
	for(int y=0;y<sy.size();y++)for(int x=0;x<sx.size();x++)if(m[y][x])r+=(long long)sx[x]*sy[y];
	return r;
}
int main(){
	int N,x1,y1,x2,y2;
	vector<pair<pair<int,int>,pair<int,int>>>v;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		v.push_back({{x1,y1},{x2,y2}});
	}
	printf("%lld\n",solve(v));
}

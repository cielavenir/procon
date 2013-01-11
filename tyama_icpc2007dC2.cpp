#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int>P;
#define Z(a,b)v.push_back(make_pair(a,b))
struct C{bool operator()(P a,P b){return a.first*a.second<b.first*b.second;}};
int main(){
	int n,w,d,p,s;
	for(;scanf("%d%d%d",&n,&w,&d),w;puts("")){
		vector<P>v;
		for(Z(w,d);n--;){
			scanf("%d%d",&p,&s);p--;s%=v[p].first+v[p].second;
			int x=v[p].first,y=v[p].second,S=0,_x=0,_y=0,x1,x2,y1,y2;
			for(;s--;)if(S==0){_x++;if(_x==x)S=1;}else _y++;
			if(S==0)x1=_x,x2=x-_x,y1=y2=y;
			else x1=x2=x,y1=_y,y2=y-_y;
			v.erase(v.begin()+p);
			if(x1*y1>x2*y2)Z(x2,y2),Z(x1,y1);
			else Z(x1,y1),Z(x2,y2);
		}
		for(sort(v.begin(),v.end(),C());v.size();){
			printf("%d",v[0].first*v[0].second);v.erase(v.begin());if(v.size())printf(" ");
		}
	}
}
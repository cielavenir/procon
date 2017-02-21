#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
  
int main(){
	vector<pair<int,pair<int,int>>> vx,vy;
	int i=0,r=0,n,x1,y1,x2,y2;
	for(scanf("%d",&n);i<n;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1>x2)swap(x1,x2);
		if(y1>y2)swap(y1,y2);
		if(x1==x2)vy.emplace_back(make_pair(x1,make_pair(y1,y2)));
		else vx.emplace_back(make_pair(y1,make_pair(x1,x2)));
	}
	//sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	for(auto &e:vx){
		auto it1=lower_bound(vy.begin(),vy.end(),make_pair(e.second.first,make_pair(-2000000000,-2000000000)));
		auto it2=lower_bound(vy.begin(),vy.end(),make_pair(e.second.second+1,make_pair(-2000000000,-2000000000)));
		
		for(;it1!=it2;++it1){
			auto &f=*it1;
			if(f.second.first<=e.first&&e.first<=f.second.second)r++;
		}
	}
	printf("%d\n",r);
}
/*
0 2 1 2
0 4 1 4
0 6 1 6
...
0 -1 0 -2
0 -3 0 -4
0 -5 0 -6
...
で落とせます
*/

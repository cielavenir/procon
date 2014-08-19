#include <cstdio>
#include <vector>
#define R second.second
#define Z(i,a,b,c)v.insert(v.begin()+i,make_pair(a,make_pair(b,c)))
using namespace std;
main(){
	int W,Q,d,w,i;char s[2];
	for(;scanf("%d%d",&W,&Q),W;puts("END")){//some case Q==0
		vector<pair<int,pair<int,int> > >v;
		for(Z(0,-2,0,0),Z(1,-1,W,0);Q;Q--)
			if(scanf("%s",s),*s-'w'){
				for(scanf("%d%d",&d,&w),i=0;~v[i].first;i++)if(v[i+1].second.first-v[i].R>=w){Z(i+1,d,v[i].R,v[i].R+w);printf("%d\n",v[i].R);break;}
				if(v[i].first==-1)puts("impossible");
			}else for(scanf("%d",&d),i=0;i<v.size();i++)if(v[i].first==d)v.erase(v.begin()+i);
	}}
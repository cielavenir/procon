#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
main(){
	int n,L,i,start,M,x,y;
	double dX,dY,dx,dy,dot,n1,n2,co,m;
	scanf("%d%d",&n,&L);
		vector<pair<pair<int,int>,int> >v;
		for(i=0;i<n;i++)scanf("%d%d",&x,&y),v.push_back(make_pair(make_pair(x,y),i));
		pair<pair<int,int>,int>p=*min_element(v.begin(),v.end());
		dX=0,dY=-1;
		start=p.second;
		vector<int>V;V.push_back(start);
		for(M=-1;M!=start;){
			m=-1,n1=hypot(dX,dY);
			for(i=0;i<n;i++){
				if(i==p.second)continue;
				dx=v[i].first.first-p.first.first,dy=v[i].first.second-p.first.second;
				dot=dX*dx+dY*dy;
				n2=hypot(dx,dy),co=dot/n1/n2;
				if(m<co)m=co,M=i;
			}
			V.push_back(M);
			dX=v[M].first.first-p.first.first,dY=v[M].first.second-p.first.second;
			p=v[M];
		}
		for(m=i=0;i<V.size()-1;i++){
			m+=hypot(v[V[i+1]].first.first-v[V[i]].first.first,v[V[i+1]].first.second-v[V[i]].first.second);
		}
		printf("%d\n",(int)(0.5+m+2*L*M_PI));
}
//live2453
//main(){int n;for(scanf("%d",&n);n--;n?puts(""):1)main2();}
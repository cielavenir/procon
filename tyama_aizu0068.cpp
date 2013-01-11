#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
main(){
	int n,i,start,M;
	double x,y,dX,dY,dx,dy,dot,n1,n2,co,m;
	for(;scanf("%d",&n),n;){
		vector<pair<pair<double,double>,int> >v;
		for(i=0;i<n;i++)scanf("%lf,%lf",&x,&y),v.push_back(make_pair(make_pair(x,y),i));
		pair<pair<double,double>,int>p=*min_element(v.begin(),v.end());
		dX=0,dY=-1;
		start=p.second;
		vector<int>V;
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
		printf("%d\n",n-V.size());
	}
}
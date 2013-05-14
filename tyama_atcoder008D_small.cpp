#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
main(){
	int m,i=0,j;
	long long n,p;
	double a,b,r;
	vector<pair<long long,
		pair<double,double>
	> >v;
	{ //compress coordinate
		set<long long>s;
		for(scanf("%lld%d",&n,&m);i<m;i++){
			scanf("%lld%lf%lf",&p,&a,&b);
			v.push_back(make_pair(p,make_pair(a,b)));
			s.insert(p);
		}
		map<long long,long long>midx;
		set<long long>::iterator it=s.begin();
		for(n=0;it!=s.end();it++,n++){
			midx[*it]=n;
		}
		for(i=0;i<m;i++){
			v[i].first=midx[v[i].first];
		}
	}
	vector<pair<double,double> >tako(n);
	double mi=1,ma=1;
	for(i=0;i<n;i++)tako[i].first=1;
	for(i=0;i<m;i++){
		tako[v[i].first].first=v[i].second.first;
		tako[v[i].first].second=v[i].second.second;
		for(r=1,j=0;j<n;j++)r=tako[j].first*r+tako[j].second;
		if(mi>r)mi=r;
		if(ma<r)ma=r;
	}
	printf("%f\n%f\n",mi,ma);
}
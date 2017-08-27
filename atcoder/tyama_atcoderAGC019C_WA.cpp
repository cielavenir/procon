#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
long long x[200002],d[200002],c[200002];

int lis(int n){
	int i,j,I;
/*
	for(i=-1;I=0,++i<n;d[i]=I+1)
		for(j=i-1;~j;j--)
			if(x[j]<x[i]&&I<d[j])I=d[j];
*/
	// http://stackoverflow.com/questions/6129682/longest-increasing-subsequenceonlogn
	int sz = 1;
	c[1] = x[0];
	d[0] = 1;
	for(i=0;++i<n;){
		if(x[i] < c[1]){
			c[1] = x[i];
			d[i] = 1;
		}else if(x[i] > c[sz]){
			c[sz+1] = x[i];
			d[i] = sz+1;
			sz++;
		}else{
			int k = lower_bound(c,c+sz,x[i])-c;
			c[k] = x[i];
			d[i] = k;
		}
	}
	for(i=j=0;i<n;i++)
		if(d[i]>d[j])j=i;
	return d[j];
}

int main(){
	long long x1,y1,x2,y2;
	int n;
	scanf("%lld%lld%lld%lld%d",&x1,&y1,&x2,&y2,&n);
	if(x1>x2)swap(x1,x2);
	if(y1>y2)swap(y1,y2);
	vector<pair<long long,long long>>v;
	for(int i=0;i<n;i++){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		if(x1<=x&&x<=x2 && y1<=y&&y<=y2)v.emplace_back(x,y);
	}
	sort(v.begin(),v.end());
	n=0;
	for(auto &e:v)x[n++]=e.second;
	n=n?lis(n):0;
	printf("%.15f\n",100LL*(x2-x1+y2-y1)-20*n+5*(n+(n>=min(x2-x1,y2-y1)+1))*3.14159265358979323846);
}

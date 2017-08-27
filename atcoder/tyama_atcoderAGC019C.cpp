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
	int x1,y1,x2,y2,n,xf=1,yf=1;
	scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n);
	if(x1>x2)swap(x1,x2),xf=-1;
	if(y1>y2)swap(y1,y2),yf=-1;
	vector<pair<int,int>>v;
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x1<=x&&x<=x2 && y1<=y&&y<=y2)v.emplace_back(x*xf,y*yf);
	}
	sort(v.begin(),v.end());
	n=0;
	for(auto &e:v)x[n++]=e.second;
	n=n?lis(n):0;
	printf("%.15f\n",100.0*(x2-x1+y2-y1)-20*n+5*(n+(n>=min(x2-x1,y2-y1)+1))*3.14159265358979323846);
}

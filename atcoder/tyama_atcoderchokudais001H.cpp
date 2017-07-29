#include <algorithm>
#include <cstdio>
int x[100001],d[100001],c[100001];

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
			int k = std::lower_bound(c,c+sz,x[i])-c;
			c[k] = x[i];
			d[i] = k;
		}
	}
	for(i=j=0;i<n;i++)
		if(d[i]>d[j])j=i;
	return d[j];
}

int n,i,T;
int main(){
	for(i=0,scanf("%d",&n);i<n;i++)scanf("%d",x+i);
	printf("%d\n",lis(n));
}

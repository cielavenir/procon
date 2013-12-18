#include <algorithm>
#include <cstdio>
int x[9999],d[9999],c[9999];

int lis(int n){
	std::reverse(x,x+n);
	int i,j,I;
/*
	for(i=-1;I=0,++i<n;d[i]=I+1)
		for(j=i-1;~j;j--)
			if(x[j]<x[i]&&I<d[j])I=d[j];
*/
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

int main(int n){
	int T=0;
	for(;n;){
		for(n=0;d[n]=c[n]=0,scanf("%d",x+n);n++)
			if(x[n]==-1)break;
		if(n)printf("Test #%d:\n  maximum possible interceptions: %d\n\n",++T,lis(n));
	}
}
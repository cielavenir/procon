#!/usr/bin/env rdmd
import core.stdc.stdio,core.atomic;
import std.range,std.parallelism;

int x[2000];
int y[2000];
int tbl[2000][2000];
pragma(inline,true): int S(int n){return n*n;}
void main(){
	int N;
	shared auto r0=0;
	shared auto r1=0;
	shared auto r2=0;
	scanf("%d",&N);
	foreach(i;iota(N))scanf("%d%d",&x[i],&y[i]);
	foreach(i;iota(N))for(int j=0;j<i;j++)tbl[i][j]=S(x[i]-x[j])+S(y[i]-y[j]);
	foreach(i;parallel(iota(N)))for(int j=0;j<i;j++)for(int k=0;k<j;k++){
		int a=tbl[i][j],b=tbl[j][k],c=tbl[i][k],m=a;
		if(m<b)m=b;
		if(m<c)m=c;
		m=a+b+c-m-m;
		r0.atomicOp!"+="(m>0);
		r1.atomicOp!"+="(m==0);
		r2.atomicOp!"+="(m<0);
	}
	printf("%d %d %d\n",r0,r1,r2);
}

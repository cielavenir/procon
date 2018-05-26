#!/usr/bin/env rdmd
//http://nabetani.sakura.ne.jp/hena/orde24tancho/
//https://qiita.com/Nabetani/items/928d6a94d83c21ef64d7

import core.stdc.stdio;

long comb(int n,int k){
	long r=1;
	for(int i=0;i<k;i++){
		r=r*(n-i)/(i+1);
	}
	return r;
}
int main(){
	int b;
	long n;
	for(;~scanf("%d,%lld",&b,&n);){
		b--;
		n--;
		int topdigit=1;
		for(;;){
			long x=comb(b,topdigit);
			if(b<topdigit || x>n)break;
			n-=x;
			topdigit++;
		}
		if(b<topdigit){
			puts("-");
			fflush(stdout);
			continue;
		}
		topdigit--;
		int curnumber=0;
		for(int d=topdigit;d>=0;d--){
			curnumber++;
			for(;;){
				long x=comb(b-curnumber,d);
				if(x>n)break;
				n-=x;
				curnumber++;
			}
			putchar(curnumber+(curnumber<10 ? 48 : 87));
		}
		puts("");
		fflush(stdout);
	}
	return 0;
}

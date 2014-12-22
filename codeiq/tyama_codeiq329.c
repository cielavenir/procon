#include <stdio.h>
long long G(long long x,long long y){return y?G(y,x%y):x;}
int main(){
	int I=0,T;
	char *sign;
	//入力は32bit整数である。しかし、
	//「約分後の分母・分子の値も符号付き32bit整数の範囲で収まる」という制約しかないので、
	//x-INT_MAX=-x+INT_MAXという問題でオーバーフローが発生する。
	//よってlong longを使わなければならない。
	long long A,b,a,B,g;
	for(scanf("%d",&T);I<T;I++){
		sign="";
		scanf("%lld%lld%lld%lld",&A,&b,&a,&B);
		A-=a,B-=b;
		if(A==0){puts("impossible");continue;}
		if(A<0)A=-A,B=-B;
		if(B==0){puts("x = 0");continue;}
		if(B<0)sign="-",B=-B;
		g=G(A,B);
		if(g==A)printf("x = %s%lld\n",sign,B/g);
		else printf("x = %s%lld/%lld\n",sign,B/g,A/g);
	}
	return 0;
}
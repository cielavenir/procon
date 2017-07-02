//http://qiita.com/Nabetani/items/705fa83cfbf20377b92f
//http://nabetani.sakura.ne.jp/hena/orde15nohil/

#include <stdio.h>
#include <stdbool.h>

typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{0,-1},{-1,0},{1,0},{0,1} // this order is important
};

void num2place(long long n, long long *px, long long *py){
	long long x=0,y=0;
	long long z=1;
	for(;n>0;){
		if(n%3==1){
			x+=z;
		}else if(n%3==2){
			y+=z;
		}
		n/=3;
		z*=2;
	}
	*px=x;
	*py=y;
}
long long place2num(long long x,long long y){
	if(x<0 || y<0 || (x&y)>0)return -1;
	long long n=0;
	long long z=1;
	for(;x>0||y>0;){
		if(x%2>0){
			n+=z;
		}else if(y%2>0){
			n+=2*z;
		}
		x/=2;
		y/=2;
		z*=3;
	}
	return n;
}
int main(){
	long long n,x,y;
	for(;~scanf("%lld",&n);){
		num2place(n,&x,&y);
		bool first=true;
		for(int i=0;i<4;i++){
			long long m=place2num(x+D[i].x,y+D[i].y);
			if(m>=0){
				if(!first)printf(",");
				first=false;
				printf("%lld",m);
			}
		}
		puts("");
		fflush(stdout);
	}
}

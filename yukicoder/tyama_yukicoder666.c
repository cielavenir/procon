//テスターやるならこういった芸もありかなと(型に注目).
#include <stdio.h>
int mul(int x,int y,int m){
	int z=0;
	for(;y;y>>=1){
		if(y&1){z+=x;if(z>=m)z-=m;}
		x+=x;if(x>=m)x-=m;
	}
	return z;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",mul(a,b,1000000007));
}

#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

int E[99][99];
int main(){
	int H,W;
	for(;~scanf("%d%d",&H,&W)&&H&&W;){
		int R=0;
		for(int h=0;h<H;h++)for(int w=0;w<W;w++){
			scanf("%d",E[h]+w);
		}
		for(int h0=0;h0<H-2;h0++)for(int h1=h0+2;h1<H;h1++)for(int w0=0;w0<W-2;w0++)for(int w1=w0+2;w1<W;w1++){
			int X=99,R0=0;
			for(int w=w0;w<=w1;w++)X=min(X,min(E[h0][w],E[h1][w]));
			for(int h=h0;h<=h1;h++)X=min(X,min(E[h][w0],E[h][w1]));
			for(int w=w0+1;w<w1;w++)for(int h=h0+1;h<h1;h++){
				if(E[h][w]>=X)R0=-1;
				if(R0>=0)R0+=X-E[h][w];
			}
			if(R0>0)R=max(R,R0);
		}
		printf("%d\n",R);
	}
}

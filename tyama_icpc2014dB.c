#include <stdio.h>
#define W 5
int m[99][W];
int main(){
	int H,h,w,i;
	for(;scanf("%d",&H),H;){
		for(h=0;h<H;h++)for(w=0;w<W;w++)scanf("%d",m[h]+w);
		int score=0,score_round=-1,cnt,color;
		for(;score_round;){
			score_round=0;
			for(h=0;h<H;h++){
				cnt=1;
				color=-1; //-1=undefined,0=empty
				for(w=0;w<W;w++){
					if(color==m[h][w])cnt++;
					else{
						if(cnt>=3)for(score_round+=cnt*color,i=w-cnt;i<w;i++)m[h][i]=0;
						cnt=1;
						color=m[h][w];
					}
				}
				if(cnt>=3)for(score_round+=cnt*color,i=w-cnt;i<w;i++)m[h][i]=0;
			}
			for(w=0;w<W;w++){
				for(i=h=H-1;h>=0;h--)if(m[h][w])m[i][w]=m[h][w],i--;
				for(;i>=0;i--)m[i][w]=0;
			}
			score+=score_round;
		}
		printf("%d\n",score);
	}
	return 0;
}
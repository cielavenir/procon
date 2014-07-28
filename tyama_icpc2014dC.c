#include <stdio.h>
#define R_MAX 20
int m[R_MAX*4+1];
int main(){
	int r,n,x1,x2,h;
	for(;scanf("%d%d",&r,&n),r;memset(m,0,sizeof(m))){
		int left=0,right=0;
		for(;n;n--){
			scanf("%d%d%d",&x1,&x2,&h);x1=2*x1+2*R_MAX;x2=2*x2+2*R_MAX;
			for(;x1<=x2;x1++)if(m[x1]<h)m[x1]=h;
		}
		//for(x1=-2*r-1;x1<=2*r+1;x1++)printf("%d %d\n",x1,m[x1+2*R_MAX]);
		//0〜2*rなるxに対する、p(x,m[x+r])との距離がrとなる、x=r上の点
		double ret=-1;
		for(x1=0;x1<=2*r;x1++){
			int x=x1-r;
			int d=x>0?x:-x;
			double y=-sqrt(r*r-d*d);
			//入出力は通っているので一安心なのですが、この辺結構怪しいです
			if(x==0){
				if(ret<0||ret>y+r+m[2*R_MAX-1])ret=y+r+m[2*R_MAX-1];
				if(ret<0||ret>y+r+m[2*R_MAX+1])ret=y+r+m[2*R_MAX+1];
			}else{
				int add=x1==0||x1==2*r?0:x/d;
				if(ret<0||ret>y+r+m[2*R_MAX+2*x+add])ret=y+r+m[2*R_MAX+2*x+add];
			}
		}
		printf("%.4f\n",ret);
	}
	return 0;
}
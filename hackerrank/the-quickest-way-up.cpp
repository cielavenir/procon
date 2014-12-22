#include <vector>
#include <cstdio>
#define DICE  6
#define ROLL  1000 //we should give up after 1000 rolls, according to the problem statement.
#define BOARD 100
using namespace std;
int main(){int T,L,S,x,y,z,i;for(scanf("%d",&T);T--;){
	double a[DICE];
	double ret=0;
	vector<double>p(BOARD);p[0]=1;
	vector<int>nxt(BOARD);
	for(i=0;i<BOARD;i++)nxt[i]=i;
	//scanf("%lf,%lf,%lf,%lf,%lf,%lf",a,a+1,a+2,a+3,a+4,a+5);
	scanf("%d,%d",&L,&S);L+=S;
	for(;L--;)scanf("%d,%d",&x,&y),nxt[x-1]=y-1;
	for(z=0;!p[BOARD-1]&&z<ROLL;z++){
		vector<double>pnxt(BOARD);
		for(x=0;x<BOARD;x++)if(p[x])for(i=0;i<DICE;i++){
			y=x+i+1;
			if(y>BOARD-1)y=x;
			y=nxt[y];
			pnxt[y]+=p[x]*(1.0/6);
		}
		//ret+=(z+1)*pnxt[BOARD-1];
		//pnxt[BOARD-1]=0;
		p=pnxt;
	}
	printf("%d\n",z);
}return 0;}
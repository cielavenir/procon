//STUCK: +15 [+6] -100 -100 -100 -100 -100 -100 0 -100 -100 -100 -100 -100 -100 +...
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
main(){
	int x,M,i,s,g,p,q,test;
	int coor[3],ab[3];
	vector<int>dice,N;
	scanf("%d",&M);
	for(i=0;i<6;i++)scanf("%d",&x),dice.push_back(x);
	scanf("%d%d",&s,&g);s--,g--;
	for(i=0;i<M;i++)scanf("%d",&x),N.push_back(x);
	for(test=0;test<3000;test++){
		scanf("%d",&x);x--;
		coor[0]=s-dice[x];
		if(coor[0]<0||M<=coor[0])coor[0]=1000;
		else{
			coor[0]+=N[coor[0]];
		}
		coor[1]=s;
		coor[2]=s+dice[x];
		if(coor[2]<0||M<=coor[2])coor[2]=1000;
		else{
			coor[2]+=N[coor[2]];
		}
		for(i=0;i<3;i++)ab[i]=abs(coor[i]-g);
		if(ab[0]<ab[1]){
			if(ab[0]<ab[2])puts("-1"),fflush(stdout),s=coor[0];
			else puts("1"),fflush(stdout),s=coor[2];
		}else{
			if(ab[1]<ab[2])puts("0"),fflush(stdout),s=coor[1];
			else puts("1"),fflush(stdout),s=coor[2];
		}
		if(s==g)break;
	}
	if(test==3000)return 1;
}
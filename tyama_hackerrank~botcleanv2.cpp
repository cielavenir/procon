#include <map>
#include <string>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> ppiii;
int D[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
string dir[]={"UP","LEFT","DOWN","RIGHT"};

char s;
int main(){
	int n=5,m=5,I,J,i,j;
	pii start=make_pair(-1,-1),goal;
	scanf("%d%d",&I,&J);getchar();
	for(i=0;i<m;getchar(),i++)for(j=0;j<n;j++){
		s=getchar();
		switch(s){
			case 'b':start=make_pair(i,j);break;
			case 'd':goal=make_pair(i,j);break;
		}
	}
	if(start==make_pair(-1,-1))puts("CLEAN"),exit(0);
	if(I%2==0){
		if(J==4)puts("DOWN");else puts("RIGHT");
	}else{
		if(J==0)puts("DOWN");else puts("LEFT");
	}
}
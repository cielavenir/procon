#include <stdio.h>
#include <string.h>
#define M 10
int a[M][M],solve[M];
main(n,i,j){
	for(scanf("%d",&n);n--;puts(i==M?"CLEAR":"FAIL")){
		for(memset(solve,i=0,M*4);i<M;i++)for(j=0;j<M;j++)scanf("%d",a[i]+j);
		for(i=0;i<M;i++){
			for(j=M-1;~j;j--)if(a[i][j]&&!solve[j]){solve[j]=1;break;}
			if(j==-1)break;
		}
	}
}
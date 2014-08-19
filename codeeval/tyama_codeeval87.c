#include <stdio.h>
M[256][256],i,j,x;char s[9];
main(int argc,char **argv){
	if(argc>1)freopen(argv[1],"rb",stdin);
	for(;~scanf("%s",s);){
		if(*s=='S'){
			scanf("%d%d",&i,&x),i--;
			if(s[3]=='R')for(j=0;j<256;j++)M[i][j]=x;
			else for(j=0;j<256;j++)M[j][i]=x;
		}else{
			scanf("%d",&i),i--;
			if(s[5]=='R')for(x=j=0;j<256;j++)x+=M[i][j];
			else for(x=j=0;j<256;j++)x+=M[j][i];
			printf("%d\n",x);
		}
	}
exit(0);}
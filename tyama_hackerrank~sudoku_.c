#include <stdio.h>
#define A(R,c,i,j)for(memset(z,0,40),R;c<9;c++)F|=m[i][j]&&++z[m[i][j]]>1;
int m[9][9],f[9][9],z[10],i,j,x,y,F;
int D(n){
	int I=n/9,J=n%9,k=0;
	if(n/81){
		for(I=0;I<9;I++)for(J=0;J<9;J++)printf(J/8?"%d\n":"%d",m[I][J]);
		fflush(stdout);
		return 1;
	}
	if(!f[I][J])return D(n+1);
	for(;++k<=9;){
		m[I][J]=k;
		A(F=j=0,j,I,j)
		A(j=i=0,i,i,J)
		A(i=I/3+J/3*3,j,i%3*3+j/3,i/3*3+j%3)
		if(!F&&D(n+1));//return 1;
	}
	return m[I][J]=0;
}
main(i,j,n){
	for(i=0;i<9;i++)for(j=-1;++j<9;f[i][j]=!m[i][j])scanf("%d",m[i]+j);
	D(0);
}
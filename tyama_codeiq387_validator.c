//compatible with C++ mode
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define N 500
char s[N*2];
int Z[10],V[N][N];
int check(){
	int i=1;
	for(;i<=9;i++)if(Z[i]!=1)return 0;
	return 1;
}
int main(){
	int r1=0,r2=0,r3=0,I,J,i,j;
	for(I=0;I<N;I++){
		scanf("%s",s);
		assert(strlen(s)==N);
		for(i=0;i<N;i++){
			assert('1'<=s[i]&&s[i]<='9');
			V[I][i]=s[i]-'0';
		}
	}
	for(I=0;I<N-8;I++)for(J=0;J<N;J++){
		memset(Z,0,sizeof(Z));
		for(i=0;i<9;i++)Z[V[I+i][J]]++;
		r1+=check();
	}
	for(I=0;I<N;I++)for(J=0;J<N-8;J++){
		memset(Z,0,sizeof(Z));
		for(j=0;j<9;j++)Z[V[I][J+j]]++;
		r2+=check();
	}
	for(I=0;I<N-2;I++)for(J=0;J<N-2;J++){
		memset(Z,0,sizeof(Z));
		for(i=0;i<3;i++)for(j=0;j<3;j++)Z[V[I+i][J+j]]++;
		r3+=check();
	}
	printf("vertical   score : %6d / %d\n",r1,N*(N-8));
	printf("horizontal score : %6d / %d\n",r2,N*(N-8));
	printf("3x3 block  score : %6d / %d\n",r3,(N-2)*(N-2));
	printf("total      score : %6d / %d\n",r1+r2+r3,2*N*(N-8)+(N-2)*(N-2));
	return 0;
}
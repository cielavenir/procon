#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define N 500
char s[N*2];
int Z[10],V[N][N],F[N][N];
int W[9][9]={
{8,7,9,3,6,5,1,4,2},
{3,6,5,1,4,2,8,7,9},
{1,4,2,8,7,9,3,6,5},
{7,9,8,6,5,3,4,2,1},
{6,5,3,4,2,1,7,9,8},
{4,2,1,7,9,8,6,5,3},
{9,8,7,5,3,6,2,1,4},
{5,3,6,2,1,4,9,8,7},
{2,1,4,9,8,7,5,3,6},
};
int perm[9]={1,2,3,4,5,6,7,8,9};

int main(int argc, char **argv){
	int r1=0,r2=0,r3=0,I,J,K,n,x,i,j;
	//FILE *testdata=fopen(argv[1],"rb");
	for(I=0;I<N;I++){
		scanf(/*testdata,*/"%s",s);
		assert(strlen(s)==N);
		for(i=0;i<N;i++){
			assert('0'<=s[i]&&s[i]<='9');
			V[I][i]=s[i]-'0';
			F[I][i]=V[I][i];
		}
	}
	//fclose(testdata);

	for(I=0;I<N;I++){
		for(J=0;J<N;J++){
			if(F[I][J]==0)V[I][J]=perm[W[I%9][J%9]-1];
		}
	}
	for(I=0;I<N;puts(""),I++)for(J=0;J<N;J++)printf("%d",V[I][J]);
	return 0;
}
/*
vertical   score :  59720 / 246000
horizontal score :  59813 / 246000
3x3 block  score :  33742 / 248004
total      score : 153275 / 740004
*/
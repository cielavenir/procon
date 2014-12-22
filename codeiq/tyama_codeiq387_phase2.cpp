// brute force phase2: test all combinations.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <algorithm>
#define N 500
char s[N*2];
int Z[10],V[N][N],F[N][N],W[9][9];
int perm[9]={1,2,3,4,5,6,7,8,9};

int main(int argc, char **argv){
	if(argc<3){
		fprintf(stderr,"give me testcase.txt and template.txt\n");
		return 1;
	}

	int r1=0,r2=0,r3=0,I,J,K,n,x,i,j;
	FILE *testdata=fopen(argv[1],"rb");
	for(I=0;I<N;I++){
		fscanf(testdata,"%s",s);
		assert(strlen(s)==N);
		for(i=0;i<N;i++){
			assert('0'<=s[i]&&s[i]<='9');
			V[I][i]=s[i]-'0';
			F[I][i]=V[I][i];
		}
	}
	fclose(testdata);
	FILE *templa=fopen(argv[2],"rb");
	for(I=0;I<9;I++){
		fscanf(templa,"%s",s);
		assert(strlen(s)==9);
		for(i=0;i<9;i++){
			assert('0'<=s[i]&&s[i]<='9');
			W[I][i]=s[i]-'0';
		}
	}
	fclose(templa);

do{
	for(I=0;I<N;I++){
		for(J=0;J<N;J++){
			if(F[I][J]==0)V[I][J]=perm[W[I%9][J%9]-1];
		}
	}
	for(I=0;I<N;puts(""),I++)for(J=0;J<N;J++)printf("%d",V[I][J]);
}while(std::next_permutation(perm,perm+9));
	return 0;
}
/*
Usage: codeiq387_phase2.cpp testcase.txt template.txt | codeiq387_validator_phase2.c

template.txt:
123456789
456789123
789123456
231564897
564897231
897231564
312645978
645978312
978312645
*/
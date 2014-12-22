//compatible with C++ mode
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define N 500
char s[N][N*2];
int Z[10],V[N][N];
int check(){
	int i=1;
	for(;i<=9;i++)if(Z[i]!=1)return 0;
	return 1;
}
int C=0,M=0;
int main(){for(;;){
	int r1=0,r2=0,r3=0,I,J,i,j;
	for(I=0;I<N;I++){
		if(scanf("%s",s[I])==EOF)return 0;
		assert(strlen(s[I])==N);
		for(i=0;i<N;i++){
			assert('1'<=s[I][i]&&s[I][i]<='9');
			V[I][i]=s[I][i]-'0';
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
	//printf("Case %d:\n",++C);
	//printf("vertical   score : %6d / %d\n",r1,N*(N-8));
	//printf("horizontal score : %6d / %d\n",r2,N*(N-8));
	//printf("3x3 block  score : %6d / %d\n",r3,(N-2)*(N-2));
	//printf("total      score : %6d / %d\n",r1+r2+r3,2*N*(N-8)+(N-2)*(N-2));
	++C;
	if(M<r1+r2+r3){
		M=r1+r2+r3;
		printf("Found %d solution (case %d):\n",M,C);
		//for(I=0;I<N;I++)puts(s[I]);
		fflush(stdout);
	}
}}
/*
Found 151864 solution (case 1):
Found 151985 solution (case 4):
Found 152054 solution (case 9):
Found 152091 solution (case 28):
Found 152209 solution (case 51):
Found 152334 solution (case 153):
Found 152406 solution (case 177):
Found 152423 solution (case 201):
Found 152511 solution (case 1497):
Found 152667 solution (case 1521):
Found 152806 solution (case 9714):
Found 152837 solution (case 11722):
Found 152900 solution (case 29706):
Found 152944 solution (case 29730):
Found 152981 solution (case 29754):
Found 152999 solution (case 118676):
Found 153157 solution (case 191156):
Found 153228 solution (case 231476):
Found 153275 solution (case 317156):
*/
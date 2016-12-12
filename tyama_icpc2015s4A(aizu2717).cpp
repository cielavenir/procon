#include <vector>
#include <cstdio>
int main(){
	int N,M,R=0,r,c,i=-1,j;
	scanf("%d%d",&N,&M);getchar();
	std::vector<int>E(N+2),W(N+2);
	for(r=N*M;++i<M;getchar())for(j=0;++j<=N;)if((c=getchar())=='E')E[j]++;else W[j]++;
	for(j=N;--j;)E[N-j+1]+=E[N-j],W[j]+=W[j+1];
	for(j=-1;++j<=N;)if(r>E[j]+W[j+1])r=E[j]+W[j+1],R=j;
	printf("%d %d\n",R,R+1);
}
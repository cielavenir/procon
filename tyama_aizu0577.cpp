#include <cstdio>
#include <map>
int M[200][3],S[200];
main(){
	int n,i=0,j=0;
	for(scanf("%d",&n);i<n;i++)scanf("%d%d%d",M[i],M[i]+1,M[i]+2);
	for(;j<3;j++){
		std::map<int,int>m;
		for(i=0;i<n;i++)m[M[i][j]]++;
		for(i=0;i<n;i++)if(m[M[i][j]]<2)S[i]+=M[i][j];
	}
	for(i=0;i<n;i++)printf("%d\n",S[i]);
}
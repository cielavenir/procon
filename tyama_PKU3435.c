int m[100][100],z[101],M;
int grid(){
	int i,j;
	for(i=0;i<M*M;i++){
		memset(z,0,sizeof(z));
		for(j=0;j<M*M;j++)if(m[i][j])z[m[i][j]]++;
		for(j=0;j<M*M;j++)if(z[m[i][j]]>1)return 0;
	}
	for(i=0;i<M*M;i++){
		memset(z,0,sizeof(z));
		for(j=0;j<M*M;j++)if(m[j][i])z[m[j][i]]++;
		for(j=0;j<M*M;j++)if(z[m[j][i]]>1)return 0;
	}
	for(i=0;i<M*M;i++){
		memset(z,0,sizeof(z));
		for(j=0;j<M*M;j++)if(m[i%M*M+j/M][i/M*M+j%M])z[m[i%M*M+j/M][i/M*M+j%M]]++;
		for(j=0;j<M*M;j++)if(z[m[i%M*M+j/M][i/M*M+j%M]]>1)return 0;
	}
	return 1;
}
int main(){
	int i,j,n;
	scanf("%d",&M);
	for(i=0;i<M*M;i++)for(j=0;j<M*M;j++)scanf("%d",m[i]+j);
	printf("%sCORRECT\n",grid()?"":"IN");
}
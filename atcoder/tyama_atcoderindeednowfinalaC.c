#include <stdio.h>

char Z[9999999];
int get(){
	static int input_count=0;
	int r=0;
	for(;'0'<=Z[input_count]&&Z[input_count]<='9';)r=r*10+Z[input_count++]-'0';
	input_count++;
	return r;
}

int dp[101][101][101];
int main(){
	fread(Z,1,sizeof(Z),stdin);
	int N=get(),M=get();
	for(;N--;){
		int a=get(),b=get(),c=get(),w=get();
		if(dp[a][b][c]<w)dp[a][b][c]=w;
	}
	{
		int i,j,k;
		for(i=0;i<=100;i++)for(j=0;j<=100;j++)for(k=0;k<=100;k++){
			if(i&&dp[i][j][k]<dp[i-1][j][k])dp[i][j][k]=dp[i-1][j][k];
			if(j&&dp[i][j][k]<dp[i][j-1][k])dp[i][j][k]=dp[i][j-1][k];
			if(k&&dp[i][j][k]<dp[i][j][k-1])dp[i][j][k]=dp[i][j][k-1];
		}
	}
	for(;M--;){
		int a=get(),b=get(),c=get();
		printf("%d\n",dp[a][b][c]);
	}
	return 0;
}

/*
2 1
0 200 200 5000
100 100 100 10000
100 100 100
*/
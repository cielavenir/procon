#include <stdio.h>
int N;
double memo[100][100][100];
double dfs(int a,int b,int c){
	if(!a&&!b&&!c)return 0;
	if(a<0||b<0||c<0)return 0;
	if(memo[a][b][c]>0)return memo[a][b][c];
	double s=a+b+c;
	return memo[a][b][c]=N/s + dfs(a,b,c-1)*c/s + dfs(a,b-1,c+1)*b/s + dfs(a-1,b+1,c)*a/s;
}	
int main(){
	int a=0,b=0,c=0,i=0,x;
	for(scanf("%d",&N);i++<N;){
		scanf("%d",&x);
		if(x==0)a++;
		if(x==1)b++;
		if(x==2)c++;
	}
	N=!printf("%f\n",dfs(a,b,c));
}
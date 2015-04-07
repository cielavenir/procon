#include <algorithm>
#include <cstdio>
#define N 5
#define TARGET 42
int a[N];
int dfs(int d,int n){
	if(d==N)return n==TARGET;
	return dfs(d+1,n+a[d])||dfs(d+1,n-a[d])||dfs(d+1,n*a[d]);
}
int main(){
	int i=0;
	for(;~scanf("%d",a+i);)if(++i==N){
		i=0;
		std::sort(a,a+N);
		do{
			if(dfs(1,*a)){puts("YES");goto NEXT;}
		}while(std::next_permutation(a,a+N));
		puts("NO");
NEXT:;
	}
}
//https://nabetani.sakura.ne.jp/ord/p.1_3jonum/
//https://zenn.dev/nabetani/scraps/9716be557f6412

#include <stdio.h>
#include <string.h>
int solve(int b, int n){
	int C[1999]; // put the memory as stack.
	int m=0, i=1;
	for(;;++i){
		memset(C, 0, b*sizeof(int));
		int x=i;
		for(;x>0;x/=b){
			if(++C[x%b]>=3)break;
		}
		if(x>0){//break above
			m++;
			if(m>=n)return i;
		}
	}
}
int main(){
	int b, n;
	for(;~scanf("%d %d", &b, &n);){
		printf("%d\n",solve(b, n));
		fflush(stdout);
	}
}

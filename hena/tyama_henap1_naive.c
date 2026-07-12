//https://nabetani.sakura.ne.jp/ord/p.1_3jonum/
//https://zenn.dev/nabetani/scraps/9716be557f6412

#include <stdio.h>
#include <string.h>
int solve(int b, int n){
	int C[1999]; // put the memory as stack.
	int m=0, i=b*b+b+1;
	for(;;){
		memset(C, 0, b*sizeof(int));
		int x=i,redun=1;
		for(;x>0;x/=b){
			int c=++C[x%b];
			if(c>=3){redun=3;break;}
			if(c>=2)redun=2;
		}
		if(redun==3){
			m++;
			if(m>=n)return i;
		}
		if(redun==1){
			i=i/b*b+b; // goto next n...n0(b) (set lowest digit 0)
		}else{
			i+=1;
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

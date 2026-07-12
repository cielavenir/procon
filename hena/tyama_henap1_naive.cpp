//https://nabetani.sakura.ne.jp/ord/p.1_3jonum/
//https://zenn.dev/nabetani/scraps/9716be557f6412

#include <cstdio>
#include <cstring>
#include <algorithm>
int C[9999];
int solve(int b, int n){
	int m=0, i=1;
	for(;;++i){
		memset(C, 0, b*sizeof(int));
		int x=i;
		for(int x=i;x>0;x/=b)C[x%b]++;
		auto it=std::max_element(C,C+b);
		if(*it>=3){
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

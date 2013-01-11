//tyama_a.c
//domestic 2007 A

#include <stdio.h>

#define max(a, b) ((a)>(b) ? (a) : (b))
#define min(a, b) ((a)<(b) ? (a) : (b))

int main(){
	int i, n, s, ma, mi, sum;
	while(1){
		ma=0; mi=1000; sum=0;
		scanf("%d", &n);
		if(!n)return 0;
		for(i=0;i<n;i++){
			scanf("%d", &s);
			ma=max(ma, s);
			mi=min(mi, s);
			sum+=s;
		}
		printf("%d\n", (sum-ma-mi)/(n-2));
	}
}
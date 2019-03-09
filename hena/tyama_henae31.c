//http://nabetani.sakura.ne.jp/hena/orde31rotnum/
//https://qiita.com/Nabetani/items/d139d5ef70aa23c2d038

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool get(int *b,int *x,int *y){
	char s[999];
	if(!fgets(s,999,stdin))return false;
	*b=strtol(strtok(s,","),NULL,10);
	*x=strtol(strtok(NULL,","),NULL,*b);
	*y=strtol(strtok(NULL,","),NULL,*b);
	return true;
}

bool chk(int n,int b){
	div_t x,y;
	x=div(n,b);
	for(;x.quot;){
		y=div(x.quot,b);
		if(y.rem!=x.rem && (y.rem+1)%b!=x.rem)return false;
		x=y;
	}
	return true;
}

int main(){
	int b,x,y;
	for(;get(&b,&x,&y);){
		int r=0;
		#pragma omp parallel for reduction(+:r)
		for(int i=x;i<=y;i++){
			r+=chk(i,b);
		}
		printf("%d\n",r);
		fflush(stdout);
	}
}

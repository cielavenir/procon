//compatible with C++ mode
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define N 500
char s[N*2];
int Z[10],V[N][N];
int check(){
	int i=1;
	for(;i<=9;i++)if(Z[i]!=1)return 0;
	return 1;
}
int lack(){ // -2:無効 -1:不定 0:完全(得点している) 1-9:欠けている数
	int i=1,x=0;
	for(;i<=9;i++){
		if(Z[i]>1)return -2;
		if(Z[i]==0){
			if(x>0)return -1;
			x=i;
		}
	}
	return x;
}
int strategy=2; //119062
int main(int argc, char **argv){
	int r1=0,r2=0,r3=0,I,J,K,n,x,i,j;
	for(I=0;I<N;I++){
		scanf("%s",s);
		assert(strlen(s)==N);
		for(i=0;i<N;i++){
			assert('0'<=s[i]&&s[i]<='9');
			V[I][i]=s[i]-'0';
		}
	}
	if(argc>1)strategy=strtol(argv[1],NULL,10);
	n=1;
	for(I=0;I<N;I++){
		n=(I+strategy%9)%9+1;
		for(J=0;J<N;J++){
			if(V[I][J]==0)V[I][J]=n;
			if(strategy/9){ //dec
				n=(n+16)%9+1;
			}else{ //inc
				n=n%9+1;
			}
		}
	}
	for(I=0;I<N;puts(""),I++)for(J=0;J<N;J++)printf("%d",V[I][J]);
	return 0;
}
/*
1〜9の数字を順番に当てはめていく。次の行は前の行の先頭の次の数字から始める。
既に数字が入っているマスは無視する。
シンプルでありながら、benchmark2.cppの約10倍のスコアを出すことができる。
*/
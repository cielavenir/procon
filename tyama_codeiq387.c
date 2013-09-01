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
int strategy=0;
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
switch(strategy){
	case 0: //72720 -> 72913
	for(I=0;I<N;I++){
		if(I>0)n=V[I-1][0]%9+1;
		for(J=0;J<N;J++){
			if(V[I][J]==0)V[I][J]=n;
			n=V[I][J]%9+1;
		}
	}break;
	case 1: //71754 -> 72012
	for(J=0;J<N;J++){
		if(J>0)n=V[0][J-1]%9+1;
		for(I=0;I<N;I++){
			if(V[I][J]==0)V[I][J]=n;
			n=V[I][J]%9+1;
		}
	}break;
	case 2: //72532 -> 72794
	for(I=0;I<N;I++){
		if(I>0)n=V[I-1][N-1]%9+1;
		for(J=N-1;J>=0;J--){
			if(V[I][J]==0)V[I][J]=n;
			n=V[I][J]%9+1;
		}
	}break;
	case 3: //71776 -> 71951
	for(J=N-1;J>=0;J--){
		if(J<N-1)n=V[0][J+1]%9+1;
		for(I=0;I<N;I++){
			if(V[I][J]==0)V[I][J]=n;
			n=V[I][J]%9+1;
		}
	}break;
	case 4: //72738 -> 72904
	for(I=N-1;I>=0;I--){
		if(I<N-1)n=V[I+1][0]%9+1;
		for(J=0;J<N;J++){
			if(V[I][J]==0)V[I][J]=n;
			n=V[I][J]%9+1;
		}
	}break;
	case 5: //71796 -> 71954
	for(J=0;J<N;J++){
		if(J>0)n=V[N-1][J-1]%9+1;
		for(I=N-1;I>=0;I--){
			if(V[I][J]==0)V[I][J]=n;
			n=V[I][J]%9+1;
		}
	}break;
	case 6: //72601 -> 72713
	for(I=N-1;I>=0;I--){
		if(I<N-1)n=V[I+1][N-1]%9+1;
		for(J=N-1;J>=0;J--){
			if(V[I][J]==0)V[I][J]=n;
			n=V[I][J]%9+1;
		}
	}break;
	case 7: //71852 -> 71986
	for(J=N-1;J>=0;J--){
		if(J<N-1)n=V[N-1][J+1]%9+1;
		for(I=N-1;I>=0;I--){
			if(V[I][J]==0)V[I][J]=n;
			n=V[I][J]%9+1;
		}
	}break;
	case 10: //71195 -> 71457
	for(K=0;K<N;K++){
		if(K>0)n=V[0][K-1]%9+1;
		for(J=K,I=0;I<K;I++){
			if(V[I][J]==0)V[I][J]=n;
			n=V[I][J]%9+1;
		}
		for(;J>=0;J--){
			if(V[I][J]==0)V[I][J]=n;
			n=V[I][J]%9+1;
		}
	}break;
	case 11: //71254 -> 71443
	for(K=0;K<N;K++){
		if(K>0)n=V[K-1][0]%9+1;
		for(I=K,J=0;J<K;J++){
			if(V[I][J]==0)V[I][J]=n;
			n=V[I][J]%9+1;
		}
		for(;I>=0;I--){
			if(V[I][J]==0)V[I][J]=n;
			n=V[I][J]%9+1;
		}
	}break;
	case 12: //71164
	for(K=0;K<N;K++){
		for(J=K,I=0;I<K;I++){
			if(V[I][J]==0){
				/*if(I>1&&J>1){
					memset(Z,0,sizeof(Z));
					for(i=-2;i<=0;i++)for(j=-2;j<=0;j++)Z[V[I+i][J+j]]++;
					x=lack();
					if(x>0)n=x;
					V[I][J]=n;
				}else if(I==0&&J>1){
					memset(Z,0,sizeof(Z));
					for(i=0;i<3;i++)for(j=-2;j<0;j++)Z[V[i][J+j]]++;
					for(x=1,i=0;i<3;x++)if(Z[x]==0)V[i++][J]=x;
				}else*/{
					V[I][J]=n;
				}
			}
			n=V[I][J]%9+1;
		}
		for(J=0;J<=K;J++){
			if(V[I][J]==0){
				/*if(I>1&&J>1){
					memset(Z,0,sizeof(Z));
					for(i=-2;i<=0;i++)for(j=-2;j<=0;j++)Z[V[I+i][J+j]]++;
					x=lack();
					if(x>0)n=x;
					V[I][J]=n;
				}else if(I>1&&J==0){
					memset(Z,0,sizeof(Z));
					for(i=-2;i<0;i++)for(j=0;j<3;j++)Z[V[I+i][j]]++;
					for(x=1,j=0;j<3;x++)if(Z[x]==0)V[I][j++]=x;
				}else*/{
					V[I][J]=n;
				}
			}
			n=V[I][J]%9+1;
		}
	}break;
}
	for(I=0;I<N;puts(""),I++)for(J=0;J<N;J++)printf("%d",V[I][J]);
	return 0;
}
/*
1〜9の数字を順番に当てはめていく。ただし既に埋まっている場所に出会ったらそこに書かれている数字の次の数字から始める。
次の行は前の行の先頭の次の数字から始めることでごくわずかながらスコアを増やすことができた。
シンプルでありながら、benchmark2.cppの約6.5倍のスコアを出すことができる。
3x3のブロックを作れるような選び方を試すこともしたが、逆にスコアが下がってしまった。
*/
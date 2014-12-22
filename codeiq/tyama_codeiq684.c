#include <stdio.h>
#include <string.h>
void my_reverse(char *a,int start,int size){
	int end=start+size-1;
	for(;start<end;start++){
		int z=a[start];a[start]=a[end];a[end]=z;
		end--;
	}
}
int main(){
	//*aで代入すると書き換え不可能。a[]は必須
#ifdef TEST
	char a[]="aaabcc";int size=6;
#else
	char a[]="abbbbcddddeefggg";int size=16;
#endif
	long long I=0;
	int i,j,k=0;
	for(;;){
		for(i=k+1;i<=size;i++){
			I++;
#ifdef TEST
			printf("%lld:",I);
			for(j=0;j<i;j++)putchar(a[j]);
			puts("");
/*
			if(i==6){
				//printf("%lld:",I);
				//for(j=0;j<i;j++)putchar(a[j]);
				//puts("");
				if(!memcmp(a,"ccbaaa",6)){
					printf("%lld\n",I); //188
					return 0;
				}
			}
*/
#else
			if(i==8){
				//printf("%lld:",I);
				//for(j=0;j<i;j++)putchar(a[j]);
				//puts("");
				if(!memcmp(a,"eagcdfbe",8)){
					printf("%lld\n",I); //5578864439
					return 0;
				}
			}
#endif
		}
		for(i=size-2;i>=0;i--)if(a[i]<a[i+1])break;
		if(i<0){
			return 0;
		}
		k=i;
		for(i=size-1;i>=k+1;i--)if(a[k]<a[i])break;
		int l=i;
		char z=a[k];a[k]=a[l];a[l]=z;
		my_reverse(a,k+1,size-(k+1));
	}
}
/*
5578864439
ENV: Ruby, C#, then C
POINT: next_permutationの変形

Narayana Panditaのアルゴリズムで順列を生成していく。
その時のKを保存しておき、aの先頭からK+1..a.size文字までを順番に列挙することでminilistは得られる。
ただし、今回はgemsのサイズが16文字と大きいため、文字通りに列挙していたのでは実行が終わらない(Ruby/C#いずれも不可だったので言語の問題では無いだろう)。
そこで、in-placeに順列を生成し(文字列をchar配列として直接いじるのはC系にしかできない芸当である)、出力サイズが8のときにmemcmpで比較する方法をとった。
clang -O3で21秒で解くことが出来た。
なおlong longは必須である。

それよりも…約15284560年ですから、今までの人類の歴史より長い年月を待たないといけませんね--;;;
*/
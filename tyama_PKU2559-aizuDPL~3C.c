#include <stdio.h>
#define SIZ 100000
int m[SIZ+1];
long long st[SIZ];

int main(){
	int N,j,ptr;
	long long r,h;
	for(;~scanf("%d",&N)&&N;){
		for(j=0;j<N;j++)scanf("%d",m+j);m[j]=0;
		for(r=ptr=j=0;j<=N;j++){
			int left=j;
			for(;ptr && (h=st[ptr-1]>>32)>m[j];){
				int l=st[--ptr]&0xffffffff;
				if(r<h*(j-l))r=h*(j-l);
				left=l;
			}
			st[ptr++]=((long long)m[j]<<32)|left;
		}
		printf("%lld\n",r);
	}
	return 0;
}

#include <stdio.h>
#define SIZ 1400
int m[SIZ+1][SIZ];
long long st[SIZ];
char z[9999999];
int get(){
	static int input_count=0;
	int r=0;
	for(;'0'<=z[input_count]&&z[input_count]<='9';)r=r*10+z[input_count++]-'0';
	input_count++;
	return r;
}
int main(){
	fread(z,1,sizeof(z),stdin);
	int i,j,k,y=get(),x=get(),r,ptr,h;
	for(j=0;j<y;j++)for(r=i=0;i<x;m[j][i]=r,i++){
		int t=get();
		r=t==0?r+1:0;
	}
	for(r=i=0;i<x;i++)for(ptr=j=0;j<=y;j++){
		int left=j;
		for(;ptr && (h=st[ptr-1]>>32)>m[j][i];){
			int l=st[--ptr]&0xffffffff;
			if(r<(j-l)*h)r=(j-l)*h;
			left=l;
		}
		st[ptr++]=((long long)m[j][i]<<32)|left;
	}

	printf("%d\n",r);
	return 0;
}
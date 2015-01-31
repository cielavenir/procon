#include <stdio.h>
#define SIZ 1400
int m[SIZ][SIZ];
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
	int i,j,k,y=get(),x=get(),r,M=0;
	for(j=0;j<y;j++)for(r=i=0;i<x;m[j][i]=r,i++){
		int t=get();
		r=t==0?r+1:0;
	}
	for(r=i=0;i<x;i++)for(j=0;j<y;j++)for(M=x,k=j;k<y;k++){
		if(M>m[k][i])M=m[k][i];
		int z=k-j+1;
		if(M<z)break;
		if(r<z)r=z;
	}
	printf("%d\n",r*r);
	return 0;
}
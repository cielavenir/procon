/* compatible with http://kk.kake.info.waseda.ac.jp/~kakehi/lp12/wl/ */
#include <stdio.h>
enum{M=1099};
bigint_init(int a[], int x){
	int z;
	z=0;
	while(z<=M){a[z]=0;z=z+1;}
	a[M]=0;
	while(x/10){a[a[M]]=x%10;a[M]=a[M]+1;x=x/10;}
	a[a[M]]=x%10;
	a[M]=a[M]+1;
}
bigint_print(int a[]){
	int i;
	i=a[M]-1;
	while(i>-1){fputc(a[i]+'0',stdout);i=i-1;}
}
bigint_add(int a[], int x[]){
	int i,c;
	i=0;
	c=0;
	while(i<M){
		a[i]=a[i]+x[i]+c;
		c=a[i]/10;
		a[i]=a[i]%10;
		if(a[i])a[M]=i+1;
		i=i+1;
	}
}
bigint_mul(int A[], int x[]){
	int i,j,c;
	int a[M];
	i=A[M]-1;c=0;
	while(c<M){a[c]=0;c=c+1;}
	c=0;
	while(i>-1){
		j=0;
		while(j<x[M]){
			a[i+j]=a[i+j]+A[i]*x[j];
			j=j+1;
		}
		i=i-1;
	}
	i=0;
	while(i<M){
		a[i]=a[i]+c;
		c=a[i]/10;a[i]=a[i]%10;
		if(a[i])A[M]=i+1;
		i=i+1;
	}
	i=0;while(i<M){A[i]=a[i];i=i+1;}
}
int main(){
	int i,n,c;
	int ten[M+1],zero[M+1],d1[M+1];
	bigint_init(ten,10);
	bigint_init(zero,0);
	n=0;
	while(1){
		int f1[M+1],f2[M+1];
		bigint_init(f1,0);
		c=fgetc(stdin);
		while('0'<=c&&c<='9'){
			bigint_mul(f1,ten);
			bigint_init(d1,c-'0');
			bigint_add(f1,d1);
			c=fgetc(stdin);
		}
		if(f1[0]==0&&f1[M]==1){return 0;}
		bigint_init(f2,0);
		c=fgetc(stdin);
		while('0'<=c&&c<='9'){
			bigint_mul(f2,ten);
			bigint_init(d1,c-'0');
			bigint_add(f2,d1);
			c=fgetc(stdin);
		}
		bigint_add(f1,f2);
		bigint_print(f1);
		fputc('\n',stdout);
	}
	return 0;
}
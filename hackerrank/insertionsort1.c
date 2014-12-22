#include <stdio.h>
#include <stdlib.h>

void insertion_sort3(int *a, int N){
	int k,i,j,t;
	for(i=1;i<N;i++){
		t = a[i];
		if(a[i-1]>t){
			j=i;
			do{
				a[j] = a[j-1];
				j--;
				for(k=0;k<N;k++)printf(k==N-1?"%d\n":"%d ",a[k]);
			}while(j>0 && a[j-1]>t);
			a[j] = t;
			for(k=0;k<N;k++)printf(k==N-1?"%d\n":"%d ",a[k]);
			exit(0);
		}
	}
}

#define M 1000
int a[M];
int main(){
	int s,i;
	for(scanf("%d",&s),i=0;i<s;i++)scanf("%d",a+i);
	insertion_sort3(a,s);
}
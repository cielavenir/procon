//http://qiita.com/Nabetani/items/dabe8ec57e0313229552
//http://nabetani.sakura.ne.jp/hena/ord17scheherazade/
#include <stdio.h>
#include <string.h>
#include <algorithm>
int a[99999];
int main(){
	int n,i,j;
	for(;~scanf("%d",&n);){
		if(n<3)puts("-");
		else{
			j=-1;
#pragma omp parallel for
			for(i=2;i<=(n-1)/2;i++){
				int n0=n;
				int n1=0;
				for(;n0;n0/=i)n1=n1*i+n0%i;
				if(n1==n)a[++j]=i;
			}
			std::sort(a,a+j+1);
			for(i=0;i<=j;i++)printf("%d,",a[i]);
			printf("%d\n",n-1);
		}
		fflush(stdout);
	}
}
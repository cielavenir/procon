//http://qiita.com/Nabetani/items/dabe8ec57e0313229552
//http://nabetani.sakura.ne.jp/hena/ord17scheherazade/
#include <stdio.h>
int main(){
	int n,i;
	for(;~scanf("%d",&n);){
		if(n<3)puts("-");
		else{
			for(i=2;i<=(n-1)/2;i++){
				int n0=n;
				int n1=0;
				for(;n0;n0/=i)n1=n1*i+n0%i;
				if(n1==n)printf("%d,",i);
			}
			printf("%d\n",n-1);
		}
		fflush(stdout);
	}
}
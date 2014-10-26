#include <stdio.h>
#define M 50000000

int t[M];
int main(){
	int N,p,q,i=3;
	t[0]=t[1]=1;
	for(p=2;p<M;p++)if(!t[p])for(q=p*2;q<M;q+=p)t[q]=1;
	p=0,q=1;
	scanf("%d",&N);
	for(;;i+=2){
		for(int j=i*i;j>=i*i-3*i+3;j+=-i+1){
			if(!t[j])p+=1;
			else q+=1;
		}
		if(p*(100-N)<q*N){
			printf("%d\n",i);
			return 0;
		}
	}
}
// 10
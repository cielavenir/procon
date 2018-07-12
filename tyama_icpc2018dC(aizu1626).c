#include <stdio.h>
int main(){
	int N;
	for(;~scanf("%d",&N)&&N;){
		int head=1,tail=1,s=0;
		for(;;){
			for(;s<N;s+=tail,tail++);
			for(;s>N;s-=head,head++);
			if(s==N){printf("%d %d\n",head,tail-head);break;}
		}
	}
}

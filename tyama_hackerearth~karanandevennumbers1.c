#include <stdio.h>

int main(){
	int N;
	for(;scanf("%d",&N),~N;)if(N%2==0)printf("%d\n",N);
    return 0;
}
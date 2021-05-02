#include <stdio.h>
int main(){
	int R=0,B=0,c;
	for(;~(c=getchar());){
		if(c=='R')R++;
		if(c=='B')B++;
	}
	puts(R>B?"TAKAHASHI":R<B?"AOKI":"DRAW");
	return 0;
}
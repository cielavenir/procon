#include <stdio.h>

char *lst[]={
	", yeah!",
	", this is crazy, I tell ya.",
	", can U believe this?",
	", eh?",
	", aw yea.",
	", yo.",
	"? No way!",
	". Awesome!",
};

int main(){
	int f=0,n=0,c;
	for(;~(c=getchar());){
		if(c=='.'||c=='!'||c=='?'){
			f^=1;
			if(!f){
				printf(lst[n]);
				n=(n+1)%8;
				continue;
			}
		}
		putchar(c);
	}
}
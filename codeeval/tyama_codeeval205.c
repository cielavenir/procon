#include <stdio.h>

int main(){
	int c,f=0,x=1;
	for(;~(c=getchar());){
		if(c=='\n'){
			putchar('\n');
			f=0;
			x=1;
		}else if(('A'<=c&&c<='Z') || ('a'<=c&&c<='z')){
			if(f*x)putchar(32);
			putchar(c|32);
			f=1;
			x=0;
		}else{
			x=1;
		}
	}
}
#include <stdio.h>
char *T="abcdefghijklmuvwxyznopqrst";
int main(){
	int c=0;
	for(;~(c=getchar());){
		if('a'<=c&&c<='z'){
			int n=(strchr(T,c)-T+13)%26;
			putchar(T[n]);
		}
		else putchar(c);
	}
	return 0;
}
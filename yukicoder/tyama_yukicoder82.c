#include <stdio.h>
const char *s="BW";
int main(){
	int W,H;
	char C;
	scanf("%d %d %c",&W,&H,&C);
	C=C=='W';
	int y,x;
	for(y=0;y<H;y++){
		for(x=0;x<W;x++){
			putchar(s[(y+x+C)%2]);
		}
		puts("");
	}
	return 0;
}
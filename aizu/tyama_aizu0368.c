#include <stdio.h>
int main(){
	int W,H;
	char S[2];
	scanf("%d%d%s",&W,&H,S);
	for(int h=0;h<H;puts(""),h++)for(int w=0;w<W;w++)putchar(
		(h==0&&w==0) || (h==0&&w==W-1) || (h==H-1&&w==0) || (h==H-1&&w==W-1) ? '+' :
		h==0 || h==H-1 ? '-' :
		w==0 || w==W-1 ? '|' :
		h==H/2&&w==W/2 ? *S : '.'
	);
}

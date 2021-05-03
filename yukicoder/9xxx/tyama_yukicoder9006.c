#include <stdio.h>
unsigned char popcnt8(unsigned char n){
	const unsigned char m1=0x55;
	const unsigned char m2=0x33;
	const unsigned char m4=0x0f;
	n=((n>>1)&m1)+(n&m1);
	n=((n>>2)&m2)+(n&m2);
	n=((n>>4)&m4)+(n&m4);
	return n;
}
unsigned char clz8(unsigned char n){
	n|=n>>1;
	n|=n>>2;
	n|=n>>4;
	return 8-popcnt8(n);
}
void rec(unsigned char *s){
	if(*s<32)return;
	int n=clz8(~*s);
	if(!n)n=1;
	rec(s+n);
	fwrite(s,1,n,stdout);
}
int main(){
	char s[768];
	fgets(s,768,stdin);
	rec((unsigned char*)s);
	return 0;
}
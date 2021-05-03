#include <stdio.h>
char z[999999];
static int input_count=0;

int get(){
	int r=0;
	for(;'0'<=z[input_count]&&z[input_count]<='9';)r=r*10+z[input_count++]-'0';
	input_count++;
	return r;
}
int getC(){
	return z[input_count++];
}
int main(){
	fread(z,1,sizeof(z),stdin);
	printf("%d ",get()+get());
    int c;
	for(;(c=getC())>0;)putchar(c);
}
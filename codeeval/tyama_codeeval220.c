#include <stdio.h>
int main(){
	int a,b,c,d,x;
	for(;~scanf("Vampires: %d, Zombies: %d, Witches: %d, Houses: %d\n",&a,&b,&c,&d);){
		printf("%d\n",d*(3*a+4*b+5*c)/(a+b+c));
	}
	return 0;
}
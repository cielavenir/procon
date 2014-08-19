#include <stdio.h>
int main(int argc, char **argv){
	int c;
	for(;~(c=getchar());putchar(tolower(c)));
	return 0;
}
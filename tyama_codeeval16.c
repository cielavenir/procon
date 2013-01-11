#include <stdio.h>
int main(int argc, char **argv){
	FILE *f=fopen(argv[1],"r");
	unsigned int u;
	int r;
	for(;~fscanf(f,"%u",&u);printf("%d\n",r))
		for(r=0;u;u>>=1)if(u&1)r++;
	fclose(f);
	return 0;
}
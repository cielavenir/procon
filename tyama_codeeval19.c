#include <stdio.h>
int main(int argc, char **argv){
	int n,p,q;
	FILE *f=fopen(argv[1],"r");
	for(;~fscanf(f,"%d,%d,%d",&n,&p,&q);)puts(((n>>(p-1))&1)==((n>>(q-1))&1)?"true":"false");
	fclose(f);
	return 0;
}
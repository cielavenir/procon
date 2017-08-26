#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv){
	FILE *f=fopen(argv[2],"r");
	int n,r;
	fscanf(f,"%d",&n);
	fclose(f);
	scanf("%d",&r);
	return !(abs(n-r)<=1);
}

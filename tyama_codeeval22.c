#include <stdio.h>
#define P 1.618034
main(int argc,char **argv){
	FILE *f=fopen(argv[1],"r");
	int n;
	double d;
	for(;~fscanf(f,"%d",&n);)
	if(n==0)puts("0");
	else{
		for(d=1;n;n--)d*=P;
		printf("%d\n",(int)(d/2.23607+0.5));
	}
	fclose(f);
	return 0;
}
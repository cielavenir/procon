#include <stdio.h>
#define P 1.618034
main(int argc,char **argv){
	if(argc>1)freopen(argv[1],"rb",stdin);
	int n;
	double d;
	for(;~scanf("%d",&n);)
	if(n==0)puts("0");
	else{
		for(d=1;n;n--)d*=P;
		printf("%d\n",(int)(d/2.23607+0.5));
	}
	return 0;
}
#include <stdio.h>
int main(int argc, char **argv){
	int n,p,q;
	if(argc>1)freopen(argv[1],"rb",stdin);
	for(;~scanf("%d,%d,%d",&n,&p,&q);)puts(((n>>(p-1))&1)==((n>>(q-1))&1)?"true":"false");
	return 0;
}
#include <stdio.h>
int main(int argc, char **argv){
	if(argc>1)freopen(argv[1],"rb",stdin);
	unsigned int u;
	int r;
	for(;~scanf("%u",&u);printf("%d\n",r))
		for(r=0;u;u>>=1)if(u&1)r++;
	return 0;
}
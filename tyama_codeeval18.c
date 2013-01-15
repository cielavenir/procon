#include <stdio.h>
int main(int argc, char **argv){
	int x,n,i;
	if(argc>1)freopen(argv[1],"rb",stdin);
	for(;~scanf("%d,%d",&x,&n);printf("%d\n",n*i))
		for(i=1;x>n*i;i++);
	return 0;
}
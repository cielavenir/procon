#include <stdio.h>
int main(int argc, char **argv){
	int x,n,i;
	FILE *f=fopen(argv[1],"r");
	for(;~fscanf(f,"%d,%d",&x,&n);printf("%d\n",n*i))
		for(i=1;x>n*i;i++);
	fclose(f);
	return 0;
}
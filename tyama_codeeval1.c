#include <stdio.h>
int main(int argc,char **argv){
	FILE *in=fopen(argv[1],"r");
	int f,b,n,i;
	for(;~fscanf(in,"%d%d%d",&f,&b,&n);){
		for(i=1;i<=n;i++){
			if(!(i%f)&&!(i%b))printf("FB");
			else if(!(i%f))putchar('F');
			else if(!(i%b))putchar('B');
			else printf("%d",i);
			if(i<n)putchar(' ');
		}
		putchar('\n');
	}
	fclose(in);
	return 0;
}
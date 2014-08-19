#include <stdio.h>
int main(int argc,char **argv){
	if(argc>1)freopen(argv[1],"rb",stdin);
	int f,b,n,i;
	for(;~scanf("%d%d%d",&f,&b,&n);){
		for(i=1;i<=n;i++){
			if(!(i%f)&&!(i%b))printf("FB");
			else if(!(i%f))putchar('F');
			else if(!(i%b))putchar('B');
			else printf("%d",i);
			if(i<n)putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
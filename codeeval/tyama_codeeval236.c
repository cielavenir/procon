#include <stdio.h>
int b,g;
int main(int c,char **a){
	freopen(a[1],"rb",stdin);
	do{
		c=getchar();
		c==' '||c=='\n'||!~c ? b&&printf("%d",b)&&(b=g=0,~c)&&putchar(c)
		: c=='|' ? printf("| ")
		: (c-='0',b=b*2+g^c,g=b&1);
	}while(~c);
	return 0;
}
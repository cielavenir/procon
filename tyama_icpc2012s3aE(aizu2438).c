#include <stdio.h>
char* F(char *b,int n,FILE *f){char *r=fgets(b,n,f);if(!r)return NULL;b[strlen(b)-1]=0;return r;}
char Q[29999],*q[9],L[29999];
n,old_indent=-1,depth=0;
main(){F(Q,sizeof(Q),stdin);q[0]=strtok(Q+1,".");for(n=1;;n++)if(!(q[n]=strtok(NULL,".")))break;for(;;){
	int indent=0;
	if(!F(L,sizeof(L),stdin))puts("no such property"),exit(0);
	for(;L[indent]==' ';indent++);
	if(old_indent>=indent)puts("no such property"),exit(0);
	char *name=strtok(L+indent,":"),*value=name+strlen(name)+1;
	if(!strcmp(name,q[depth]))if(old_indent=indent,depth++,depth==n)
		if(*value)printf("string \"%s\"\n",value+1),exit(0);
		else puts("object"),exit(0);
}}
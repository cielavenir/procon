#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned char *a;
static void execute(char *p, int braincrash){
	char *x=p,c;
	int i=0,marker=0;
	while(c=*(x+i)){
		i++;
		switch(c){
			case '>': a++;break;
			case '<': a--;break;
			case '+': (*a)++;break;
			case '-': (*a)--;break;
			case '.': putchar(*a);break;
			case ',': *a=getchar();break;
			case '[':{
				if(*a)execute(x+i,0);
				for(marker=1;marker;i++){
					if(*(x+i)=='[')marker++;
					if(*(x+i)==']')marker--;
				}
			}break;
			case ']': if(*a)i=0;else return;break;

			//braincrash
			case '|': if(braincrash){a++;*a|=*(a-1);}break;
			case '&': if(braincrash){a++;*a&=*(a-1);}break;
			case '~': if(braincrash){*a=~(*a);}break;
			case '^': if(braincrash){a++;*a^=*(a-1);}break;

			default:{
				fprintf(stderr,"internal error: operation %c\n",c);
				return;
			}
		}
	}
	if(braincrash)for(;*a;a++)putchar(*a);
}

int main(){
	int braincrash=0;
	unsigned char *da;
	char *p,*x;

	p=(char*)",----------------.>++++++++++.";
	da=(unsigned char*)malloc(0x20000);
	memset(da,0,0x20000);
	a=da+0x10000;

	if(braincrash)strcpy((char*)a,"Hello, world!");
	execute(p,braincrash);
	free(da);
	return 0;
}
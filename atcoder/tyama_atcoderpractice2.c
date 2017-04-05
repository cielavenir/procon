#include <stdio.h>
#include <stdlib.h>
char s[27],t[2];
int f(char *a,char *b){
	fflush(!printf("? %c %c\n",*a,*b));
	scanf("%s",t);
	return *t=='<' ? -1 : 1;
}
void z(char *a,char *b){
	*a^=*b,*b^=*a,*a^=*b;
}
int main(){
	int N,i;
	scanf("%d%d",&N,&i);
	for(i=0;i<N;i++)s[i]=65+i;
	if(N>5)qsort(s,N,1,f);
	else{
		//http://stackoverflow.com/a/1535000
		if(f(s+0,s+1)>0)z(s+0,s+1);
		if(f(s+2,s+3)>0)z(s+2,s+3);
		if(f(s+0,s+2)>0)z(s+0,s+2),z(s+1,s+3);
		if(f(s+2,s+4)>0){
			z(s+4,s+3),z(s+3,s+2);
			//ABECD
			if(f(s+0,s+2)>0){
				z(s+2,s+1),z(s+1,s+0);
				if(f(s+2,s+3)>0){
					z(s+2,s+3);
					if(f(s+3,s+4)>0)z(s+3,s+4);
				}
			}else{
				if(f(s+1,s+3)>0){
					z(s+1,s+2),z(s+2,s+3);
					if(f(s+3,s+4)>0)z(s+3,s+4);
				}else{
					if(f(s+1,s+2)>0)z(s+1,s+2);
				}
			}
		}else{
			if(f(s+3,s+4)>0)z(s+3,s+4);
			if(f(s+1,s+3)>0){
				z(s+1,s+2),z(s+2,s+3);
				if(f(s+3,s+4)>0)z(s+3,s+4);
			}else{
				if(f(s+1,s+2)>0)z(s+1,s+2);
			}
		}
	}
	printf("! %s\n",s);
}

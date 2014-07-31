#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE 1100
char M[1001][LINE];
char* myfgets(char *b,int n,FILE *f){
	char *r=fgets(b,n,f);
	if(!r)return NULL;
	if(b[strlen(b)-1]=='\n')b[strlen(b)-1]=0;
	if(b[strlen(b)-1]=='\r')b[strlen(b)-1]=0;
	return r;
}
int main(){
	int n,i,j,k;
	for(;myfgets(*M,LINE,stdin),n=strtol(*M,NULL,10);){
		memset(M,0,sizeof(M));
		for(i=0;i<n;i++)myfgets(M[i],LINE,stdin);
		for(i=0;i<n;i++){
			for(j=0;M[i][j]=='.';j++)M[i][j]=' ';
			if(j)M[i][j-1]='+';
		}
		for(i=n-1;i;i--){
			for(j=0;M[i][j]!='+';j++);
			for(k=i-1;M[k][j]==' ';k--)M[k][j]='|';
		}
		for(i=0;i<n;i++)puts(M[i]);
	}
	return 0;
}
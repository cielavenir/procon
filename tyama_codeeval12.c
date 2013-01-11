#include <stdio.h>
char s[20];a[256];
int main(int argc,char **argv){
	int i,l;
	FILE *f=fopen(argv[1],"r");
	for(;~(fscanf(f,"%s",s));){
		memset(a,0,sizeof(a));
		l=strlen(s);
		for(i=0;i<l;i++)a[s[i]]++;
		for(i=0;i<l;i++)if(a[s[i]]==1){printf("%c\n",s[i]);break;}
	}
	fclose(f);
	return 0;
}
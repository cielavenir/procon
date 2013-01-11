#include <stdio.h>
char s[20];a[10];
int main(int argc,char **argv){
	int i,l;
	FILE *f=fopen(argv[1],"r");
	for(;~(fscanf(f,"%s",s));){
		memset(a,0,sizeof(a));
		l=strlen(s);
		for(i=0;i<l;i++)a[s[i]-'0']++;
		for(i=0;i<l;i++)if(a[i]!=s[i]-'0')break;
		puts(i==l?"1":"0");
	}
	fclose(f);
	return 0;
}
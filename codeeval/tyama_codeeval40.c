#include <stdio.h>
char s[20];a[10];
int main(int argc,char **argv){
	int i,l;
	if(argc>1)freopen(argv[1],"rb",stdin);
	for(;~scanf("%s",s);){
		memset(a,0,sizeof(a));
		l=strlen(s);
		for(i=0;i<l;i++)a[s[i]-'0']++;
		for(i=0;i<l;i++)if(a[i]!=s[i]-'0')break;
		puts(i==l?"1":"0");
	}
	return 0;
}
#include <stdio.h>
char s[20];a[256];
int main(int argc,char **argv){
	int i,l;
	if(argc>1)freopen(argv[1],"rb",stdin);
	for(;~scanf("%s",s);){
		memset(a,0,sizeof(a));
		l=strlen(s);
		for(i=0;i<l;i++)a[s[i]]++;
		for(i=0;i<l;i++)if(a[s[i]]==1){printf("%c\n",s[i]);break;}
	}
	return 0;
}
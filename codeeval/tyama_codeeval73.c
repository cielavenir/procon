#include <stdio.h>
char s[99];a[99],i;main(int argc, char **argv){if(argc>1)freopen(argv[1],"rb",stdin);for(*s=1;~scanf("%s",s+1);printf("%d\n",a[strlen(s)-1]))
for(a[0]=a[1]=1,i=2;i<strlen(s);i++)a[i]=
	s[i]=='0'?a[i-2]:
	s[i-1]>'2'||(s[i-1]=='2'&&s[i]>'6')?a[i-1]:
	(a[i-2]+a[i-1]);
}
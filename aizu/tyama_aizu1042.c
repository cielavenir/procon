#include <stdio.h>
char *p,s[999];main(i){for(;fgets(s,999,stdin),memcmp(p=s,"END OF I",8);puts(""))for(s[strlen(s)-1]=' ';*p;printf("%d",i))for(i=0;*p++!=' ';i++);exit(0);}
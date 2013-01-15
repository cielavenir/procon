#include <stdio.h>
a,b,c,d,e,f,g,h;
main(int argc, char **argv){
if(argc>1)freopen(argv[1],"rb",stdin);
for(;~scanf("%d,%d,%d,%d,%d,%d,%d,%d",&a,&b,&c,&d,&e,&f,&g,&h);puts(a>=g||e>=c||h>=b||d>=f?"False":"True"));exit(0);}
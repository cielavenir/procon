#include <stdio.h>
a[256];
int main(int argc,char **argv){
	int i,c;
	if(argc>1)freopen(argv[1],"rb",stdin);
	for(;~(c=getchar());){
		if(c=='\n'){
			for(c=0,i='a';i<='z';i++)
				if(!a[i])putchar(i),c++;
			puts(c?"":"NULL");
			memset(a,0,sizeof(a));
			continue;
		}
		if('A'<=c&&c<='Z')c+=32;
		a[c]++;
	}
	return 0;
}
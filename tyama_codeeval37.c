#include <stdio.h>
a[256];
int main(int argc,char **argv){
	int i,c;
	FILE *f=fopen(argv[1],"r");
	for(;~(c=fgetc(f));){
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
	fclose(f);
	return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define between(a,x,b) ((a)<=(x)&&(x)<=(b))
int main(const int argc, const char **argv){
char s[99];
	int i=1,j,k,l;
	for(;~scanf("%s",s);){l=strlen(s);
		for(j=0;j<l;j++)
			if(!between('0',s[j],'9'))break;
		for(k=0;k<l;k++)
			if(!(between('a',s[k],'z')||between('A',s[k],'Z')))break;
		if(j<l&&k<l)return 1;//{printf("illegal format.\n");continue;}
		if(j==l){ //NUM to AL
			unsigned long long int r=strtoull(s,0,10)+1;
			int flg=0;
			char xxx[30];
			for(j=0;r;j++,r/=26){
				xxx[j]=r%26+'A'-1-flg;
				flg=0;
				if(xxx[j]=='@')xxx[j]='Z',flg=1;
				if(xxx[j]=='?')xxx[j]='Y',flg=1;
			}
			if(flg)j--,xxx[j]=0;
			for(j--;j>=0;j--){
				putchar(xxx[j]);
			}
			putchar('\n');
		}
		if(k==l){ //AL to NUM
			unsigned long long int r=0;
			for(k=0;k<l;k++){
				int c=s[k];
				if(between('a',s[k],'z'))c-=0x20;
				r*=26;
				r+=c-'A'+1;
			}
			printf("%llu\n",r-1);
		}
	}
	return 0;
}
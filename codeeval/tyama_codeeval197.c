#include <stdio.h>
int main(){
	int j,r;
	for(;~scanf("%d",&r);){
		int flg=0;
		char xxx[30];
		for(j=0;r;j++,r/=26){
			xxx[j]=r%26+'A'-1-flg;
			flg=0;
			if(xxx[j]=='@')xxx[j]='Z',flg=1;
		}
		if(flg)j--,xxx[j]=0;
		for(j--;j>=0;j--){
			putchar(xxx[j]);
		}
		putchar('\n');
	}
	return 0;
}
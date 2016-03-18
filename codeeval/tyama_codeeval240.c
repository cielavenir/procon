#include <stdio.h>
//https://oeis.org/A001348

int main(int argc,char **argv){
	//freopen(argv[1],"r",stdin);
	int N;
	for(;~scanf("%d",&N);){
		if(N>3)printf("3");
		if(N>7)printf(", 7");
		if(N>31)printf(", 31");
		if(N>127)printf(", 127");
		if(N>2047)printf(", 2047");
		if(N>8191)printf(", 8191");
		puts("");
	}
}
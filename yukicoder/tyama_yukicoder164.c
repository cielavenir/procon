#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned long long ull;
int main(){
	ull R=1ULL<<63;
	int N,B,i;
	char s[99];
	for(scanf("%d",&N);N--;){
		scanf("%s",s);
		for(B=i=0;i<strlen(s);i++){
			int b=s[i]>=65?s[i]-55:s[i]-48;
			if(B<b)B=b;
		}
		//B+1==16の時先頭の0Xを読むので、strtoullの失敗による制御は不可
		ull r=strtoull(s,NULL,B+1);
		if(R>r)R=r;
	}
	printf("%llu\n",R);
	return 0;
}
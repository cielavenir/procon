#include <stdio.h>
char s[99];
int main(){
	int n=0,i,r;
	for(;~(s[n]=getchar());){
		if(s[n]=='\n'){
			for(r=1,i=0;i<n/2;i++){
				if(s[i]=='*'&&s[i+n/2]=='*')r*=2;
				if(s[i]!='*'&&s[i+n/2]!='*'&&s[i]!=s[i+n/2])r=0;
			}
			printf("%d\n",r);
			n=0;
		}else{
			n++;
		}
	}
	if(n){
			for(r=1,i=0;i<n/2;i++){
				if(s[i]=='*'&&s[i+n/2]=='*')r*=2;
				if(s[i]!='*'&&s[i+n/2]!='*'&&s[i]!=s[i+n/2])r=0;
			}
			printf("%d\n",r);
	}
	return 0;
}
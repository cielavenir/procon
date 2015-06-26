//usr/bin/picoc $0 - $@;exit
#include <stdio.h>
int main(){
	int a,b,c,t=0,i;
	scanf("%d%d%d",&a,&b,&c);
	for(i=0;i<60;i++){
		if(c<=t+a)break;
		t+=a+b;
		for(;c<=t;)c+=60;
	}
	printf("%d\n",i==60?-1:c);
	return 0;
}
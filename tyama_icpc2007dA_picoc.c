//usr/bin/env picoc $0 - $@;exit

#include <stdio.h>
int i,n,s,M,m,S;
int main(){for(scanf("%d",&n);n;scanf("%d",&n)){
	i=S=M=0;
	for(m=1000;i<n;i++){
		scanf("%d",&s);M=M>s?M:s;
		m=m<s?m:s;
		S+=s;
	}
	printf("%d\n",(S-M-m)/(n-2));
}return 0;}
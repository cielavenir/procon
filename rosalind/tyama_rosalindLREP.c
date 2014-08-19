/*
O(N^2), around 3mins with optimization.
By the way, this is fake.
TCACACTCACACAC$
5
must output "CAC".
*/
#include <stdio.h>
char s[19999];a[19999],N,n[19999],k,M,L;main(i,j){
	scanf("%s%d",s,&N);
	s[strlen(s)-1]=0;
	for(i=0;i<strlen(s)-L;i++){
	fprintf(stderr,"%d %d %d\n",i,L,M);
		memset(n,0,sizeof(n));
		for(k=0,j=i+1;j<strlen(s);j++){
			for(;k>0&&s[j]!=s[i+k];)k=a[k-1];
			if(s[j]==s[i+k]){
				k++;
				if(++n[k]==N-1&&k>L)L=k,M=i;
			}
			a[j]=k;
		}
		a[i]=0;
	}
	//printf("%d %d\n",L,M);
	for(i=M;i<M+L;i++)putchar(s[i]);
	puts("");
}
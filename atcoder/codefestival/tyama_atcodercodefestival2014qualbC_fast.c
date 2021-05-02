#include <stdio.h>
#include <string.h>
#define SIZ 26
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
char Z[100001];
int A[SIZ],B[SIZ],C[SIZ];
int main(){
	int l,i,a=0,b=0;
	scanf("%s",Z);
	l=strlen(Z);
	for(i=0;i<l;i++)A[Z[i]-'A']++;
	scanf("%s",Z);
	for(i=0;i<l;i++)B[Z[i]-'A']++;
	scanf("%s",Z);
	for(i=0;i<l;i++)C[Z[i]-'A']++;
#if 1
	for(i=0;i<SIZ&&A[i]+B[i]>=C[i];i++){
		a+=min(A[i],C[i]);
		b+=min(B[i],C[i]);
	}
	puts(i==SIZ&&l/2<=b&&l/2<=a?"YES":"NO");
#else
	for(i=0;i<SIZ&&A[i]+B[i]>=C[i];i++){
		a+=min(A[i],C[i]);
		b+=max(C[i]-B[i],0);
	}
	puts(i==SIZ&&b<=l/2&&l/2<=a?"YES":"NO");
#endif
	return 0;
}
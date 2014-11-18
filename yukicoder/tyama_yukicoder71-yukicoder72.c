#include <stdio.h>
int main(){
	long long n,x,y;
	scanf("%lld",&n);
	x=n/2;
	y=n-x;
	//printf("%lld\n",(x+1)*(y+1)-1); //71
	printf("%lld\n",((__int128_t)(x+1)*(y+1)-1)%1000007); //72
	return 0;
}
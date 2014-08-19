#include <stdio.h>
#define abs(a) ((a)<0?-(a):(a))
//Used JD-GUI.
int main(){
	long long s1=1070107010701LL;
	long long s2=1992993994995LL;
	long long v=114514810893LL;
	int i=0;
	for(;i<100;i++)v=abs(v*s1+s2);
	printf("%lld\n",v);
	return 0;
}
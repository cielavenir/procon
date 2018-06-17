#include <cstdio>
#include <algorithm>
unsigned int a[6000000];
int main(){
	unsigned int i=0,n=0,m=0,t,x,y=1,z=2,w=3;
	scanf("%u",&x);
	for(;i<10000001;i++){
		t = (x^(x<<11));
		x = y;
		y = z;
		z = w;
		w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
		if(w<0x70000000)m++;
		else if(w<0x90000000)a[n++]=w;
	}
	std::sort(a,a+n);
	printf("%u\n",a[5000000-m]);
}

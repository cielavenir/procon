#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
char buf[2000];
int list[1000000];
int main() {
	fgets(buf,2000,stdin);
	if(*buf=='T'){
		double x1,y1,x2,y2;
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		printf("%.5f\n",hypot(x1-x2,y1-y2));
	}else if(*buf=='C'){
		long long a,b;
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",a+b);
	}else if(*buf=='E'){
		for(int i=0;i<1000000;i++)scanf("%d",list+i);
        sort(list,list+1000000);
        for(int i=0;i<1000000;i++)printf("%d\n",list[i]);
	}else puts("42");
	return 0;
}
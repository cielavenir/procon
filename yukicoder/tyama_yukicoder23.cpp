#include <vector>
#include <algorithm>
#include <cstdio>
int main(){
	int h,a,d;
	scanf("%d%d%d",&h,&a,&d);
	std::vector<int>r(h+1);
	for(int i=1;i<=h;i++){
		r[i]=std::min((i>=a?r[i-a]:0)+2,(i>=d?r[i-d]:0)+3);
	}
	printf("%d.%d\n",r[h]/2,r[h]%2*5);
}
#include <algorithm>
#include <cstdio>

int main(){
	int a[4];
	scanf("%d%d%d%d",a,a+1,a+2,a+3);
	std::sort(a,a+4);
	puts(a[0]==a[1]&&a[2]==a[3] ? "yes" : "no");
}

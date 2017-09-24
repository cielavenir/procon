#include <stdio.h>
int main(){
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if((a<=x&&x<b) || (a<y&&y<=b) || (x<a&&b<=y)){puts("1");return 0;}
	}
	puts("0");
}

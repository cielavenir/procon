//usr/bin/env picoc $0 - $@;exit
#include <stdio.h>
int main(){
	int n,t=0,x=0,y=0;
	for(scanf("%d",&n);n--;){
		int t0,x0,y0;
		scanf("%d%d%d",&t0,&x0,&y0);
		{
			int dt=t0-t,dx=x0-x,dy=y0-y;
			if(dx+dy>dt || (dt-dx-dy)%2){
				puts("No");
				return 0;
			}
		}
		t=t0;x=x0;y=y0;
	}
	puts("Yes");
	return 0;
}

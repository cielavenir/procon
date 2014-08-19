#include <stdio.h>
main(){
	double h,v,g,y,Y,S=1.41421356;
	puts("? 0\n? 2\n? 4");fflush(stdout);
	scanf("%lf",&h);
	scanf("%lf",&y);y-=h;
	scanf("%lf",&Y);Y-=h;
	printf("! %lf %lf %lf\n",h,y/S+S*(g=y/2-Y/4),g);
}
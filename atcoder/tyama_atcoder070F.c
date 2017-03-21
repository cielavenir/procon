#include <stdio.h>
z[9999],a,b,c;
f(x,y){
	fflush(!printf("? %d %d\n",x,y));
	scanf("%s",&b);
	b=b=='Y';
}
main(i){
	if(scanf("%d%d",&a,&b),a<=b){puts("Impossible");return;}
	for(i=a+=b;~--i;)!c||f(i,z[c-1])?(z[c++]=i):c--;
	for(c=*z,i=a;~--i;)z[i]=f(c,i);
	for(printf("! "),i=0;i<a;)printf("%d",z[i++]);
}

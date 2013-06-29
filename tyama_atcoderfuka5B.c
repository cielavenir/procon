#include <time.h>
char S[99];
struct tm T;
main(Y,M,x){if(sizeof(time_t)<8)exit(1);
for(;scanf("%d/%d/%d %d:%d:%d",&Y,&M,&T.tm_mday,&T.tm_hour,&T.tm_min,&T.tm_sec),Y;){
	scanf("%s",S),x=(1<<strlen(S))-1;
	T.tm_year=Y-1900;
	T.tm_mon=M-1;
	time_t t=mktime(&T)+x;
	localtime_r(&t,&T);
	printf("%d/%02d/%02d %02d:%02d:%02d\n",T.tm_year+1900,T.tm_mon+1,T.tm_mday,T.tm_hour,T.tm_min,T.tm_sec);
}exit(0);}
#include <time.h>
char s[99];
struct tm T;
main(i,j,a,b,c,d,e){
	if(sizeof(time_t)<8)exit(1);
	time_t t,t0=1356015600;
	for(;scanf("%s",s),*s!='#';){
		for(j=i=0;i<strlen(s);i++)if(s[i]=='.')j++;
		if(j==2){
			sscanf(s,"%d.%d.%d",&a,&b,&c);
			T.tm_year=a-1900;
			T.tm_mon=b-1;
			T.tm_mday=c;
			t=(mktime(&T)-t0)/86400%1872000;
			printf("%lld.%lld.%lld.%lld.%lld\n",t/144000,t/7200%20,t/360%20,t/20%18,t%20);
		}else{
			sscanf(s,"%d.%d.%d.%d.%d",&a,&b,&c,&d,&e);
			t=(a*144000LL+b*7200+c*360+d*20+e)*86400+t0;
			localtime_r(&t,&T);
			printf("%d.%d.%d\n",T.tm_year+1900,T.tm_mon+1,T.tm_mday);
		}
	}
exit(0);}
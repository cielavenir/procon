#define M 1000000
main(r,a,w,W,t,i,I){
	for(r=0,a=3;a<=M/4+1;a++)for(t=(a-1)*4,r++,i=a-2,I=t-8;t+I<=M&&i>=3;)t+=I,r++,i-=2,I-=8;
	printf("%d\n",r);
}
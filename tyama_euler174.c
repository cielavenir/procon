#define M 1000000
T[M+1];
main(r,a,w,W,t,i,I){
	for(a=3;a<=M/4+1;a++)for(t=(a-1)*4,T[t]++,i=a-2,I=t-8;t+I<=M&&i>=3;)t+=I,T[t]++,i-=2,I-=8;
	for(r=a=0;a<=M;a++)if(0<T[a]&&T[a]<11)r++;
	printf("%d\n",r);
}
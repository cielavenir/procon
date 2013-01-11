long long A[99999],r=0,s=0;
#define tri(a,b,c) (a<b+c)
int compare(const void *a, const void *b){
	long long val=*(long long*)b - *(long long*)a;
	return val<0?-1:val>0?1:0;
}
main(){
	int N,i=0;
	scanf("%d",&N);
	if(N<6)puts("0"),exit(0);
	for(i=0;i<N;i++)scanf("%lld",A+i);
	qsort(A,N,8,compare);
	for(i=0;i<N-5;i++) //single*2
		if(tri(A[i],A[i+1],A[i+2])){s=A[i]+A[i+1]+A[i+2];break;}
	if(s)for(i+=3;i<N-2;i++)
		if(tri(A[i],A[i+1],A[i+2])){r=s+A[i]+A[i+1]+A[i+2];break;}
	for(s=i=0;i<N-5;i++)
		if(
			(tri(A[i],A[i+1],A[i+4])&&tri(A[i+2],A[i+3],A[i+5]))|| //type3 AABBAB
			(tri(A[i],A[i+1],A[i+5])&&tri(A[i+2],A[i+3],A[i+4]))|| //type4 AABBBA
			(tri(A[i],A[i+3],A[i+4])&&tri(A[i+1],A[i+2],A[i+5]))   //type8 ABBAAB
		){s=A[i]+A[i+1]+A[i+2]+A[i+3]+A[i+4]+A[i+5];r=r>s?r:s;break;}
	printf("%lld\n",r);exit(0);
}
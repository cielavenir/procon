R=1<<30;main(){
	unsigned long long x,X,p,a,A,b,r=1;
	scanf("%llu%llu%llu%llu",&x,&p,&a,&b);
	if(b-a>p)R=1;
	else{for(A=a,X=x;A;X=X*X%p,A/=2)if(A&1)r=r*X%p;for(;a<=b;a++)R=R<r?R:r,r=r*x%p;}
	R=!printf("%d\n",R);
}
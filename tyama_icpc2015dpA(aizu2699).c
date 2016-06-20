a,b;double f(x){return fabs(b-sqrt(x*x+(a-x)*(a-x)));}
main(x){for(;scanf("%d%d",&a,&b),a;){
	x=2*b*b < a*a ? a/2 : (a-sqrt(2*b*b - a*a))/2;
	printf("%f\n",a<b ? b-a : fmin(f(x),f(-~x)));
}}
//x*x + a*a - 2*a*x + x*x = b*b <=> x = (2*a + sqrt(8*b*b - 4*a*a)) / 4
//ただし判定式<0に注意
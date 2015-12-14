M=1000000007,H,W,i,r;long long I[1000001],F[1000001],c=1;
int gcd(x,y){return y?gcd(y,x%y):x;}
long long lcm(x,y){return (long long)x/gcd(x,y)*y;}
main(d){
	scanf("%d%d",&H,&W);
	d=gcd(H,W);
	I[1]=F[0]=F[1]=1;
	for(i=2;i<=d;i++){I[i]=M-(M/i)*I[M%i]%M;F[i]=F[i-1]*I[i]%M;c=c*i%M;}
	for(i=0;i<=d;i++){if(lcm(W/gcd(W,i),H/gcd(H,d-i))==(long long)H/d*W)r=(r+c*F[i]%M*F[d-i])%M;}
	c=!printf("%d\n",r);
}
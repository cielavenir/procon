#define max(a,b)((a)>(b)?(a):(b))
lcs[2002][2002],a[2002],b[2002];
main(){
	int i,j,A,B,n,x;
	for(scanf("%d",&n);n--;printf("%d\n",x)){
		for(x=A=1;scanf("%d",a+A);A++)if(!a[A])break;
		Z:for(B=1;scanf("%d",b+B);B++)if(!b[B]){
			if(B<2)break;
			for(i=1;i<A;i++)for(j=1;j<B;j++){
				lcs[i][j]=max(max(lcs[i-1][j],lcs[i][j-1]),lcs[i-1][j-1]+(a[i]==b[j]));
			}
			x=max(x,lcs[A-1][B-1]);
			goto Z;
		}
	}
}
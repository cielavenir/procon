n,T[101],M[101][4][4];int D(d,a,b){
if(d==n+1)return 1;
if(T[d])return T[d]!=a||T[d]!=b?D(d+1,T[d],a):0;
int i=1,s=0;
for(;i<=3;i++)if(i!=a||i!=b){
	if(!M[d+1][i][a])M[d+1][i][a]=D(d+1,i,a)%10000;
	s+=M[d+1][i][a];
}
return s;}
main(k,x,y){for(scanf("%d%d",&n,&k);k;k--)scanf("%d%d",&x,&y),T[x]=y;printf("%d\n",D(1,0,0)%10000);exit(0);}
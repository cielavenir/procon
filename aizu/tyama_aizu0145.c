i,F[100],B[100],M[100][100];int D(f,l){
if(~M[f][l])return M[f][l];
if(f==l)return 0;
int x=0x7fffffff,y,i=f;
for(;i<l;i++)if(x>(y=D(f,i)+D(i+1,l)+F[f]*B[i]*F[i+1]*B[l]))x=y;
return M[f][l]=x;}
main(n){memset(M,0xff,sizeof(M));for(scanf("%d",&n);i<n;i++)scanf("%d%d",F+i,B+i);printf("%d\n",D(0,n-1));exit(0);}
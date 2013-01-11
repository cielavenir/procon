int m,n,P[1000],b[500],r[500],i,j,t;
char C[1000][1000],V[1000];
int h(x,y){return y?h(y,x%y):x;}
int g(x,y){return x>y?h(x,y):h(y,x);}
int match(s){int i=m;for(;i<m+n;i++)if(C[s][i]&&!V[i])if(V[i]=1,P[i]<0||match(P[i]))return P[s]=i,P[i]=s,1;return 0;}
main(){
  for(;scanf("%d%d",&m,&n),m;printf("%d\n",t)){
    memset(&C,0,sizeof(C)),memset(&P,0xff,sizeof(P));
    for(i=0;i<m;i++)scanf("%d",b+i);
    for(j=0;j<n;j++)scanf("%d",r+j);
    for(i=0;i<m;i++)for(j=0;j<n;j++)C[i][j+m]=C[j+m][i]=g(b[i],r[j])>=2;
    for(t=i=0;i<m;i++)memset(&V,0,sizeof(V)),t+=match(i);
  }
  return 0;
}
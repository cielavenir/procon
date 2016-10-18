#define min(a,b) ((a)<(b)?(a):(b))
main(x,y,i,j,n,a,b,c,d){
  int m[99][99];
  memset(m,0,sizeof(m));
  m[0][0]=1;

  scanf("%d%d%d",&x,&y,&n);
  for(;n;n--){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a==c)m[2*a][2*min(b,d)+1]=1;
    else m[2*min(a,c)+1][2*b]=1;
  }

  for(i=0;i<=2*x;i+=2)
    for(j=0;j<=2*y;j+=2){
      if(i>0&&!m[i-1][j])m[i][j]+=m[i-2][j];
      if(j>0&&!m[i][j-1])m[i][j]+=m[i][j-2];
    }

  printf(m[2*x][2*y]?"%d\n":"Miserable Hokusai!\n",m[2*x][2*y]);
  return 0;
}
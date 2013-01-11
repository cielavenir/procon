#define max(a,b) ((a)>(b)?(a):(b))
short lcs[4002][4002];

int main(){
  char a[4002],b[4002];
  int i,j,_a,_b,m;
  while(~scanf("%s%s",a+1,b+1)){
    memset(lcs,0,sizeof(lcs));
    _a=strlen(a+1);_b=strlen(b+1);
    for(m=0,i=1;i<=_a;i++)
      for(j=1;j<=_b;j++){
        lcs[i][j]=a[i]==b[j]?lcs[i-1][j-1]+1:0;
        if(m<lcs[i][j])m=lcs[i][j];
      }
    printf("%d\n",m);
  }
  return 0;
}
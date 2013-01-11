#define max(a,b) ((a)>(b)?(a):(b))
int lcs[500][500];

int main(){
  char a[500],b[500];
  int i,j,_a,_b;
  while(~scanf("%s%s",a+1,b+1)){
    memset(lcs,0,sizeof(lcs));
    _a=strlen(a+1);_b=strlen(b+1);
    for(i=1;i<=_a;i++)
      for(j=1;j<=_b;j++)
        lcs[i][j]=max(max(lcs[i-1][j],lcs[i][j-1]),lcs[i-1][j-1]+(a[i]==b[j]));
    printf("%d\n",lcs[_a][_b]);
  }
}
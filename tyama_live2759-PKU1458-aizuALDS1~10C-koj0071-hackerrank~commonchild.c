#define M 500
//500 for PKU1458, 1002 for aizuALDS1~10C/koj0071, 5002 for hackerrank~commonchild
#define max(a,b) ((a)>(b)?(a):(b))
int lcs[M][M];

int main(){
  char a[M],b[M];
  int i,j,_a,_b;
  //scanf("%d",&i); //aizuALDS1~10C
  scanf("%d%d",&i,&i); //koj0071
  while(~scanf("%s%s",a+1,b+1)){
    memset(lcs,0,sizeof(lcs));
    _a=strlen(a+1);_b=strlen(b+1);
    for(i=1;i<=_a;i++)
      for(j=1;j<=_b;j++)
        lcs[i][j]=max(max(lcs[i-1][j],lcs[i][j-1]),lcs[i-1][j-1]+(a[i]==b[j]));
    printf("%d\n",lcs[_a][_b]);
  }
}
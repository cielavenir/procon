char m[200][202];
int a[201];

int main(){
  int x,y,i=0,j=0,k;
  scanf("%d%d",&y,&x);
  for(;i<y;i++)
  scanf("%s",m[i]);
  for(;j<x;a[k]++,j++)
    for(i=k=0;i<y;i++)
      if(m[i][j]-'0')a[k]++,k=0;
      else k++;
  for(i=1;i<201;i++)
    if(a[i])
      printf("%d %d\n",i,a[i]);
}
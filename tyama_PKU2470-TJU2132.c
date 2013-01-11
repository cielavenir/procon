int x[100001];
int y[100001];
int main(){
  int n,i;
  while(1){
    scanf("%d",&n);
    if(!n)return 0;
    for(i=1;i<=n;i++)
      scanf("%d",x+i);
    for(i=1;i<=n;i++)
      y[x[i]]=i;
    if(memcmp(x+1,y+1,4*n))
      printf("not ");
    printf("ambiguous\n");
  }
}
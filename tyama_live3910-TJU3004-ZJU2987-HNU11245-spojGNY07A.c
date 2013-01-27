int main(){
  int i,n,j;
  char w[82];
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    printf("%d ",i);
    scanf("%d%s",&j,w);
    w[j-1]=0;
    printf("%s%s\n",w,w+j);
  }
  return 0;
}
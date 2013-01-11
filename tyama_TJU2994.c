int x[2][10];
int vec(int m){
  int i,r=0;
  for(i=0;i<m;i++)scanf("%d",x[0]+i);
  for(i=0;i<m;i++)scanf("%d",x[1]+i);
  for(i=0;i<m;i++)r+=x[0][i]*x[1][i];
  return r;
}

int main(){
  int i=0,n,m;
  scanf("%d",&n);
  for(;i<n;i++){
    scanf("%d",&m);
    printf("%d\n",vec(m));
  }
}
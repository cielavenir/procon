int main(){
  int i,j=0,n=1;
  int x[10001];
  for(i=1;i<=10000;i++){
    x[i]=n+x[i-1];
    j++;
    if(j==n){j=0;n++;}
  }
  
  /*ZJU2345 bootstrap*/
  /*scanf("%d",&n);for(j=0;j<n;j++){*/
  while(1){
    scanf("%d",&i);
    if(!i)break;
    printf("%d %d\n",i,x[i]);
  }
  /*if(j!=(n-1))puts("");}*/
  return 0;
}
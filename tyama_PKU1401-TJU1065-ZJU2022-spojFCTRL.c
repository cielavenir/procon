void factorial(int x){
  int r=0;
  while(x){
    x/=5;
    r+=x;
  }
  printf("%d\n",r);
}

int main(){
  int i,n,x;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&x);
    factorial(x);
  }
}
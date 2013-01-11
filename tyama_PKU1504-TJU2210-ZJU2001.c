int reverse(int n){
  int ret=0;
  while(n){ret=ret*10+n%10;n/=10;}
  return ret;
}

int main(){
  int a,b,n;
  scanf("%d",&n);
  for(;n;n--){
    scanf("%d%d",&a,&b);
    printf("%d\n",reverse(reverse(a)+reverse(b)));
  }
}
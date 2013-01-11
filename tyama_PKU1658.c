int main(){
  int n,a,b,c,d;
  scanf("%d",&n);
  for(;n;n--){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%d %d %d %d %d\n",a,b,c,d,c-b==b-a?d+b-a:d*b/a);
  }
}
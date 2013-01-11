int main(){
  int n,x,s,t;
  scanf("%d",&n);
  for(;n;n--){
    scanf("%d",&x);
    t=-x+1;
    for(;x;x--){
      scanf("%d", &s);
      t+=s;
    }
    printf("%d\n", t);
  }
}
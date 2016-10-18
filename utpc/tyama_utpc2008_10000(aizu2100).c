void sai(int n){
  int i=1,ma=0,mi=0,a,b;
  scanf("%d",&a);
  for(;i<n;i++){
    scanf("%d",&b);
    if(ma<b-a)ma=b-a;
    if(mi>b-a)mi=b-a;
    a=b;
  }
  printf("%d %d\n",ma,-mi);
}

int main(){
  int i=0,n,x;
  scanf("%d",&n);
  for(;i<n;i++){
    scanf("%d",&x);
    sai(x);
  }
  return 0;
}
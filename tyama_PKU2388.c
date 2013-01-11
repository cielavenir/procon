char s[1000001];

int median(int n){
  int i,x;
  for(i=0;i<n;i++){
    scanf("%d",&x);
    s[x]++;
  }
  n/=2;x=0;
  for(i=0;i<=1000000;i++){
    x+=s[i];
    if(x>n)break;
  }
  return i;
}

int main(){
  int n;
  scanf("%d",&n);
  printf("%d",median(n));
  return 0;
}
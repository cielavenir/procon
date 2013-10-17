int q(char *p){
  int r=0,i=0;
  for(;i<8;i++)
    r+=r+p[i]-'0';
  return r;
}

int main(){
  int n;
  char p[33];
  scanf("%d",&n);
  for(;n;n--){
  scanf("%s",p);
  printf("%d.%d.%d.%d\n",q(p),q(p+8),q(p+16),q(p+24));
  }
}
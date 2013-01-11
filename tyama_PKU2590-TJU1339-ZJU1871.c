int step(int n){
  int i=2,ret=0,x;
  if(n<=2)return n;
  while(1){
    ret+=i;x=n-ret;
    if(x<=0)return i;
    if(x<=(i>>1)+1)return i+1;
    i+=2;
  }
}

int main(){
  int x,y,n;
  scanf("%d",&n);
  for(;n;n--){
    scanf("%d%d",&x,&y);
    printf("%d\n",step(y-x));
  }
  return 0;
}

/*bootstrap for ZJU1871*/
/*main(x,y){for(;~scanf("%d%d",&x,&y);printf("%d\n",step(y-x));}*/
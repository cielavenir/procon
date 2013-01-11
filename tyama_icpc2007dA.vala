#!/usr/bin/vala
static void main(){
  int i, n, s, ma, mi, sum;
  while(true){
    ma=0; mi=1000; sum=0;
    stdin.scanf("%d",out n);
    if(n==0)return;
    for(i=0;i<n;i++){
      stdin.scanf("%d",out s);
      ma=ma>s?ma:s;
      mi=mi<s?mi:s;
      sum+=s;
    }
    stdout.printf("%d\n",(sum-ma-mi)/(n-2));
  }
}
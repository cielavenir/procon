//utpc2008_10001.c‚æ‚èˆø—p
int kan(int n){
  int sum=1,i=2;
  double s=sqrt(n);
  if(n<6)return -1;
  for(;i<s;i++){
    if(n%i==0)sum += i+n/i;
  }
  if(floor(s)==s&&n%(int)s==0)sum+=s;
  return sum-n;
}

int main(){
  int n,r;
  puts("PERFECTION OUTPUT");
  while(1){
    scanf("%d",&n);
    if(n==0)break;
    printf("%5d  ",n);
    r=kan(n);
    if(r<0)puts("DEFICIENT");
    if(r==0)puts("PERFECT");
    if(r>0)puts("ABUNDANT");
  }
  puts("END OF OUTPUT");
}
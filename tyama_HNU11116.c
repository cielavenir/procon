int x[1001]; /* I set this 100001 for 11120, but I got TLE */

int main(){
  int n,i,m,r,y;
  while(scanf("%d",&n),n){
    for(i=1;i<=n;i++)scanf("%d",x+i);
    scanf("%d",&m);
    for(;m;m--){
      r=1;
      scanf("%d%d",&i,&y);
      for(;i<=y;i++)r=(r*x[i])%10007;
      printf("%d",r);
    }
    printf("\n");
  }
  return 0; /* hoj requires this phrase :) */
}
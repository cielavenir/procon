#include <math.h>

int table[500001];

int kan(int n){
  int sum=1,i=2;
  double s=sqrt(n);
  if(n==1)return 0;
  for(;i<s;i++){
    if(n%i==0)sum += i+n/i;
  }
  if(floor(s)==s&&n%(int)s==0)sum+=s;
  return sum;
}

int main(){
  int i,j;
  memset(table,0,sizeof(table));
  for(i=1;i<=500000;i++)
    for(j=2;i*j<=500000;j++)
      table[i*j]+=i;
  scanf("%d",&i);
  for(;i;i--){
    scanf("%d",&j);
    printf("%d\n",table[j]);
  }
}
int table[300000];

int main(){
  int i,j,n;
  for(i=7;i<=300000;i+=7){
    table[i-1]=1;
    table[i+1]=1;
  }
  for(i=7;i<=300000;i+=7){
    if(table[i-1])
      for(j=(i-1)*2;j<=300000;j+=i-1)table[j]=0;
    if(table[i+1])
      for(j=(i+1)*2;j<=300000;j+=i+1)table[j]=0;
  }

  while(1){
    scanf("%d",&n);
    if(n==1)return 0;
    printf("%d:",n);
    for(i=7;i<=n+1;i+=7){
      if(table[i-1] && !(n%(i-1)))printf(" %d",i-1);
      if(table[i+1] && !(n%(i+1)))printf(" %d",i+1);
    }
    puts("");
  }
}
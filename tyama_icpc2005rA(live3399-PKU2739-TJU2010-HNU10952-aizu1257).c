#define IN_MAX 10000
char primes[IN_MAX+1];
int prime[300];
int table[IN_MAX+1];

void createtable(){
  int i=2,j,n=0;
  primes[1]=1;
  for(;i<=IN_MAX;i++)
    if(!primes[i])
      for(j=i*2;j<=IN_MAX;j+=i)
        primes[j]=1;

  for(i=2;i<=IN_MAX;i++)
    if(!primes[i])prime[n++]=i;
    
  for(i=0;i<n;i++){
    int x=prime[i];
    table[x]++;
    for(j=i+1;;j++){
      x+=prime[j];
      if(x>IN_MAX)break;
      table[x]++;
    }
  }
}

int main(){
  int n;
  createtable();
  while(1){
    scanf("%d",&n);
    if(!n)return 0;
    printf("%d\n",table[n]);
  }
}
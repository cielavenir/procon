#define IN_MAX 31622777
#define PRIME 1952000

char table[IN_MAX+1];
int prime[PRIME];

createtable(){ //0->prime 1->not prime
  int i=3,j,k=1;
  prime[0]=2;
  for(;i<=IN_MAX;i+=2)
    if(!table[i]){
      prime[k++]=i;
      for(j=i*2;j<=IN_MAX;j+=i)
        table[j]=1;
    }
}

main(i){
  long long x;
  createtable();
  for(;scanf("%lld",&x),x;printf("%d\n",prime[i]))
    for(i=0;i<PRIME;i++)
      if(!(x%prime[i]))break;
  return 0;
}
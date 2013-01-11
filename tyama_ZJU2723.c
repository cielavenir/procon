#define MAX 1000000

char primes[MAX+1];
char table[MAX+1];

void createtable(){
  int i,j;
  for(i=2;i<=MAX;i++)
    if(!primes[i])
      for(j=2*i;j<=MAX;j+=i)
        primes[j]=1;
  for(i=2;i<=MAX;i++)
    for(j=i;j<=MAX/i;j++)
      if(!primes[i]&&!primes[j])table[i*j]=1;
}

main(n){createtable();for(;~scanf("%d",&n);printf(table[n]?"Yes\n":"No\n"));}
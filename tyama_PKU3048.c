//‘S•”1‚È“ü—Í‚ª‚ ‚é‚Æ‚©•³‚¾w
#define MAX 20000

char table[MAX+1];

void createtable(){
  int i=2,j;
  table[0]=table[1]=1;
  for(;i<=MAX;i++)
    if(!table[i])
      for(j=i*2;j<=MAX;j+=i)
        table[j]=1;
}

main(m,n,x,i,r){createtable();scanf("%d",&n);
  for(r=1;n;n--){
    scanf("%d",&x);
    for(i=19999;i;i--)
      if(!table[i]&&!(x%i))break;
    if(m<i)m=i,r=x;
  }
  printf("%d\n",r);
}
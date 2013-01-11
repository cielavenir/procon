int p[1000002];
int x[1000002];

void createtable1(){
  int i,j;
  memset(p,0,sizeof(p));
  for(i=5;i<=1000001;i+=4)
    if(!p[i])
      for(j=i*2;j<=1000001;j+=i)p[j]=1;
}

void createtable2(){
  int i,j,k=0;
  memset(x,0,sizeof(x));
  for(i=5;i<=1000001;i+=4)
    for(j=i;j<=1000001/i;j+=4)
      if(!p[i] && !p[j])
        x[i*j]=1;
  for(i=5;i<=1000001;i+=4){
    if(x[i])k++;
    x[i]=k;
  }
}

int main(){
  int i,s,n;
  createtable1();
  createtable2();
  while(1){
    scanf("%d",&n);
    if(!n)return 0;
    printf("%d %d\n",n,x[n]);
  }
}
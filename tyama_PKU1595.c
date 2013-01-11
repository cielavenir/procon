#define MAX 1001
int prime[MAX];
int p[MAX];

int main(){
  int i,j,k,n,c,x;
  prime[0]=-1;prime[1]=0;p[0]=1;
  for(k=1,i=2;i<MAX;i++)
    if(!prime[i])
      for(prime[i]=k,p[k++]=i,j=i*2;j<MAX;j+=i)
        prime[j]=-1;
  for(;~scanf("%d%d",&n,&c);puts("\n")){
    printf("%d %d:",n,c);
    for(;prime[n]<0;n--);
    x=prime[n];
    if(x<c*2){
      for(i=0;i<=x;i++)printf(" %d",p[i]);
    }else if(x&1){/*odd*/
      for(i=x/2-c+1;i<x/2+c+1;i++)printf(" %d",p[i]);
    }else{
      for(i=x/2-c+1;i<x/2+c;i++)printf(" %d",p[i]);
    }
  }
}
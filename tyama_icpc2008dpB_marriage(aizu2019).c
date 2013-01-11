#define min(a,b) ((a)<(b)?(a):(b))
int x[10000][2];

int compare(const void* p1, const void *p2){return ((int*)p2)[1]-((int*)p1)[1];}

int guard(int n,int m){
  int i,s=0;
  memset(x,0,sizeof(x));
  for(i=0;i<n;i++)scanf("%d%d",x[i],x[i]+1);
  qsort(x,n,sizeof(x[0]),compare);
  for(i=0;i<n;i++){
    int t=min(m,x[i][0]);
    m-=t;x[i][0]-=t;
    if(!m)break;
  }
  for(;i<n;i++)s+=x[i][0]*x[i][1];
  return s;
}

int main(){
  int n,m;
  while(1){
    scanf("%d%d",&n,&m);
    if(!n&&!m)return 0;
    printf("%d\n",guard(n,m));
  }
}
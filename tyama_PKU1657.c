#define between(a,x,b) ( ((a)<=(x))&&((x)<=(b)) )
#define max(a,b) ((a)<(b)?(b):(a))
#define abs(a) ((a)<0?-(a):(a))

void king(int i, int j){
  printf("%d ",max(i,j));
}

void queen(int i, int j){
  printf("%d ",i==j||!i||!j?1:2);
}

void luke(int i, int j){
  printf("%d ",!i||!j?1:2);
}

void ele(int i, int j){
  if((i+j)&1)printf("Inf\n");
  else printf("%d\n",i==j?1:2);
}

int main(){
  char s1[3],s2[3];
  int a,b,c,d,i,j,n;
  scanf("%d",&n);
  for(;n;n--){
    if(scanf("%s %s",s1,s2)<0)return 0;
    a=s1[0]-'a',b=s2[0]-'a';
    c=s1[1]-'1',d=s2[1]-'1';
    i=abs(a-b),j=abs(c-d);
    if(!i&&!j){puts("0 0 0 0");continue;}
    king(i,j);
    queen(i,j);
    luke(i,j);
    ele(i,j);
  }
}
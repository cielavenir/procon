#define between(a,x,b) ((a)<=(x)&&(x)<(b))

char table[10000]={0};
int x,y,f,c,m;

void check(a,b){
  int _f=0;
  if(!between(0,a,x)||!between(0,b,y))return;
  if(!table[a*100+b])return;
  table[a*100+b]=0;

  if(!f){f=_f=1;}
  c++;
  check(a-1,b);
  check(a,b-1);
  check(a,b+1);
  check(a+1,b);
  if(_f){f=0;if(m<c)m=c;c=0;}
}

int main(){
  int n,p,q;
  scanf("%d%d%d",&x,&y,&n);
  for(m=0;n;n--){
    scanf("%d%d",&p,&q);
    table[(p-1)*100+(q-1)]=1;
  }
  for(p=0;p<x;p++)
    for(q=0;q<y;q++)
      check(p,q);
  printf("%d\n",m);
  return 0;
}
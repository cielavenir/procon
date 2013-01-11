int m[101][101];

void a(x,y,l,b){
  int i,j;
  for(i=x;i<x+l;i++)
    for(j=y;j<y+l;j++)
      m[i][j]=b;
}

void t(x,y,l){
  int i,j,s=0;
  for(i=x;i<x+l;i++)
    for(j=y;j<y+l;j++)
      if(m[i][j])s++;
  printf("%d\n",s);
}

int main(){
  int n,x,y,l;
  char p[6];
  scanf("%d",&n);
  for(;n;n--){
    scanf("%s%d%d%d",p,&x,&y,&l);
    switch(*p){
      case 'B': a(x,y,l,1);break;
      case 'W': a(x,y,l,0);break;
      case 'T': t(x,y,l);
    }
  }
}
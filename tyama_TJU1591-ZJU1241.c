int main(){
  int i=0,a,b,c;
  while(scanf("%d%d%d",&a,&b,&c),a){
    printf("Triangle #%d\n",++i);
    if(a==-1)
      if(b>c)
        printf("Impossible.\n");
      else
        printf("a = %.3f\n",sqrt(c*c-b*b));
    if(b==-1)
      if(a>c)
        printf("Impossible.\n");
      else
        printf("b = %.3f\n",sqrt(c*c-a*a));
    if(c==-1)printf("c = %.3f\n",sqrt(a*a+b*b));
    puts("");
  }
  return 0;
}
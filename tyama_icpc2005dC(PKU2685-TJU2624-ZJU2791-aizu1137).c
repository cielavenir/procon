int parse(char *p){
  int r=0,i=1;
  for(;*p;p++){
    if(isdigit(*p)){i=*p-'0';continue;}
    switch(*p){
      case 'm':r+=i*1000;break;
      case 'c':r+=i*100;break;
      case 'x':r+=i*10;break;
      case 'i':r+=i;break;
    }
    i=1;
  }
  return r;
}

void output(int n){
  int i,x;
  if(x=n/1000){
    if(x>1)printf("%d",x);
    printf("m");
  }
  if(x=n/100%10){
    if(x>1)printf("%d",x);
    printf("c");
  }
  if(x=n/10%10){
    if(x>1)printf("%d",x);
    printf("x");
  }
  if(x=n%10){
    if(x>1)printf("%d",x);
    printf("i");
  }
  puts("");
}

int main(n){
  char p[9],q[9];
  scanf("%d",&n);
  for(;n;n--){
    scanf("%s%s",p,q);
    output(parse(p)+parse(q));
  }
  return 0;
}
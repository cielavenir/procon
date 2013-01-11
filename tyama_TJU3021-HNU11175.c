int index(char *s,int c){char *p=strchr(s,c);return p&&c?p-s:-1;}

int get(char *s){
  char unit[8]="IVXLCDM\0";
  int i=0,_s=strlen(s),r=0,iunit[7]={1,5,10,50,100,500,1000};
  for(;i<_s;i++){
    int x=index(unit,s[i]);
    if(x<index(unit,s[i+1]))r-=iunit[x];else r+=iunit[x];
  }
  return r;
}

output(int a){
  int i;
  for(i=0;i<a/1000;i++)putchar('M');
  if(a/100%10==9)printf("CM");
  else if(a/100%10==4)printf("CD");
  else{
    if(a/100%10>4)putchar('D');
    for(i=0;i<a/100%5;i++)putchar('C');
  }
  if(a/10%10==9)printf("XC");
  else if(a/10%10==4)printf("XL");
  else{
    if(a/10%10>4)putchar('L');
    for(i=0;i<a/10%5;i++)putchar('X');
  }
  if(a%10==9)printf("IX");
  else if(a%10==4)printf("IV");
  else{
    if(a%10>4)putchar('V');
    for(i=0;i<a%5;i++)putchar('I');
  }
}

main(c,s,n,i){
  char x[20];
  loop:
  scanf("%d",&n);
  if(!n)return;
  printf("Case ");
  output(c);
  printf(": ");
  for(i=s=0;i<n;i++){
    scanf("%s",x);
    s+=get(x);
  }
  output(s);
  puts("");
  c++;
  goto loop;
}
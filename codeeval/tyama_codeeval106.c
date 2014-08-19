//TJU3021
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
  puts("");
}

main(n){for(;~scanf("%d",&n);)output(n);}
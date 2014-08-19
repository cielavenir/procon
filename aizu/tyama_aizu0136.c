float f;
int a[7];
main(n,i){
  for(scanf("%d",&n);n--;a[i]++)
    scanf("%f",&f),i=f<165?1:f<170?2:f<175?3:f<180?4:f<185?5:6;
  for(i=1;i<7;puts(""),i++)
    for(printf("%d:",i);a[i]--;putchar('*'));
  return 0;
}
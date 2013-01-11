int a[9];
main(){
  int i=0,j=0,s=0;
  for(;j<9;j++)
    scanf("%d",a+j),s+=a[j];
  s-=100;
  for(;i<8;i++)
    for(j=i+1;j<9;j++)
      if(a[i]+a[j]==s)goto z;
z:
  for(s=0;s<9;s++)
    if(s!=i&&s!=j)printf("%d\n",a[s]);
}
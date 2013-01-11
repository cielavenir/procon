#define max(a,b)((a)>(b)?(a):(b))
main(a,b,n,m){
  a=getchar();b=getchar();getchar();
  n=getchar();m=getchar();
  printf("%d\n",max(abs(a-n),abs(b-m)));
  while(a!=n){
    if(a<n)printf("R"),a++;
    if(a>n)printf("L"),a--;
    if(b<m)printf("U"),b++;
    if(b>m)printf("D"),b--;
    puts("");
  }
  while(b!=m){
    if(b<m)puts("U"),b++;
    if(b>m)puts("D"),b--;
  }
  return 0;
}
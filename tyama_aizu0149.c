float f,g;
int a[4],b[4];
main(i,j){
  for(;~scanf("%f%f",&f,&g);a[i]++,b[j]++)
    i=f<0.2?3:f<0.6?2:f<1.1?1:0,j=g<0.2?3:g<0.6?2:g<1.1?1:0;
  for(i=0;i<4;i++)
    printf("%d %d\n",a[i],b[i]);
  return 0;
}
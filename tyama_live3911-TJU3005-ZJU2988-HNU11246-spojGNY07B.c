int main(){
  int n,i=1;
  char s[3];
  float f;

  scanf("%d",&n);
  for(;i<=n;i++){
    printf("%d ",i);
    scanf("%f%s",&f,s);

    if(s[0]=='k')
      printf("%.4f lb\n",2.2046*f);
    if(s[0]=='g')
      printf("%.4f l\n",3.7854*f);
    if(s[0]=='l')
      if(s[1]=='b')
        printf("%.4f kg\n",0.4536*f);
      else
        printf("%.4f g\n",0.2642*f);
  }
}
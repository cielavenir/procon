main(i,j){
  char s[11];
  for(;~scanf("%s",&s);printf("%c\n",*s))
    for(i=9;i--;)
      for(j=0;j<9;j++)
        s[j]=(s[j]+s[j+1]-2*'0')%10+'0';
  return 0;
}
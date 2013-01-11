char m[8][11]={
  "*****     ",
  "     *****",
  "==========",
  " **** ****",
  "* **** ***",
  "** **** **",
  "*** **** *",
  "**** **** "
};

main(f,i,j){
  char s[9];
  for(f=0;~scanf("%s",s);){
    if(f)puts("");
    f=1;
    for(i=0;i<8;puts(""),i++){
      for(j=0;j<5-strlen(s);j++)
        putchar(m[i][0]);
      for(j=0;j<strlen(s);j++)
        putchar(m[i][s[j]-'0']);
    }
  }
  return 0;
}
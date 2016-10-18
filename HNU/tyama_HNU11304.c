char s[101],t[101];
main(d,i){
  for(;scanf("%s%s",s,t)>1;printf("Hamming distance is %d.\n",d))
    for(d=i=0;i<strlen(s);i++)
      if(s[i]-t[i])d++;
  return 0;
}
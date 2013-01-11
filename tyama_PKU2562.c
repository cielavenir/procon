char s[10],t[10];
main(m,n,i,j,c,r){
  for(;scanf("%s%s",s,t),*s-'0'|*t-'0';printf(r?"%d":"No",r),printf(" carry operation%s.\n",r>1?"s":"")){
    m=strlen(s)-1,n=strlen(t)-1;
    for(r=c=0;m>=0||n>=0;m--,n--){
      i=m<0?0:s[m]-'0';
      j=n<0?0:t[n]-'0';
      if(i+j+c>9)c=1,r++;else c=0;
    }
  }
}
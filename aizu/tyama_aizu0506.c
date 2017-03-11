char a[999999],b[999999],*p;
main(i,n,c,s,d,l){
  for(;~scanf("%d",&n)&&n;printf("%s\n",a)){
    scanf("%s",a);
    for(;n;n--){
      for(p=b,i=d=s=0,l=strlen(a);i<=l;i++){
        c=a[i];
        if(!s)s=c;
        if(s!=c){
          p+=sprintf(p,"%d",d);
          *(p++)=s;
          d=0;s=c;
        }
        d++;
      }
      *p=0;
      strcpy(a,b);
    }
  }
  return 0;
}

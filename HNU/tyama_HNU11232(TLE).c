char a[100000],b[100000],*p,*q;
main(i,d){
  for(;scanf("%s%s",a,b),*a-'*';){
    p=q=0;
    for(i=0;i<strlen(a);i++)
      {if(!p&&a[i]!='0')p=a+i;if(a[i]>64)a[i]-=7;}
    if(!p)p="0";
    for(i=0;i<strlen(b);i++)
      {if(!q&&b[i]!='0')q=b+i;if(b[i]>64)b[i]-=7;}
    if(!q)q="0";
    if(!(d=strlen(q)-strlen(p)))d=strcmp(p,q);
    printf("%c\n",d<0?'<':d>0?'>':'=');
  }
  return 0;
}
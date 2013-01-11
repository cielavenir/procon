main(i,l){
  char s[100001],t[100001],x[101],y[101],*p,*q;
  scanf("%s%s%s",s,x,y);
  {for(i=0,l=strlen(s);i<l;i++)t[i]=s[l-i-1];}
  p=strstr(s,x);if(p)p=strstr(p+strlen(x),y);
  q=strstr(t,x);if(q)q=strstr(q+strlen(x),y);
  if(p){
    if(q)puts("both");
    else puts("forward");
  }else{
    if(q)puts("backward");
    else puts("fantasy");
  }
  return 0;
}
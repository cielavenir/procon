char s[100],c;a[256];b[256];
int p(char *s,int *l,int *r){
  int x=0,y=0,i=1,c=1,l1,r1,l2,r2;

  if(*s=='('){
    x=p(s+1,&l1,&r1);
    for(;c;i++){if(s[i]=='(')c++;if(s[i]==')')c--;}
  }else
    l1=a[*s],r1=b[*s];

  if(s[i]=='('){i++;
    y=p(s+i,&l2,&r2);
  }else
    l2=a[s[i]],r2=b[s[i]];

  *l=l1,*r=r2;return x+y+l1*r1*r2;
}
main(i,x,y){
  for(scanf("%d",&i);i--;a[c]=x,b[c]=y)scanf(" %c%d%d",&c,&x,&y);
  for(;~scanf("%s",s);){
    if(*s-'('){puts("0");goto e;}
    for(x=i=0;i<strlen(s);i++){
      if(s[i]-'('&&s[i]-')')
        if(x&&x!=a[s[i]]){puts("error");goto e;}
      x=b[s[i]];
    }
    printf("%d\n",p(s+1,&x,&y));
e:;
  }
}
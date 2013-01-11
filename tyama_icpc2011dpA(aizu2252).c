char *R="yuiophjklnm",s[33];
#define z(i) (strchr(R,s[i])?0:1)
int main(i,l,r,x){
  for(;scanf("%s",s),*s-'#';printf("%d\n",r))
    for(x=z(0),l=strlen(s),i=1,r=0;i<l;i++)
      if(x!=z(i))r++,x^=1;
exit(0);}
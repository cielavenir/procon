int main(){
  int x[11],i,n;
  char s[6];
  memset(x,0,sizeof(x));
  while(1){
    scanf("%d",&n);
    if(!n)return 0;
    scanf("%s",s);
    scanf("%s",s);
    if(s[0]=='h')
      for(i=n;i<11;i++)
        x[i]=1;
    else if(s[0]=='l')
      for(i=n;i;i--)
        x[i]=1;
    else{
      printf(x[n] ? "Stan is dishonest\n" : "Stan may be honest\n");
      memset(x,0,sizeof(x));
    }
  }
}
int main(){
  int i,j,n,s;
  char p[201],q[201];
  while(scanf("%d",&n),n){
    memset(p,0,sizeof(p));
    memset(q,0,sizeof(q));
    scanf("%s",p);
    s=strlen(p);
    strcpy(q,p);
    for(i=n;i<s;i+=2*n)
      for(j=0;j<n;j++)
        q[i+j]=p[i+n-j-1];
    for(i=0;i<n;i++)
      for(j=i;j<s;j+=n)
        printf("%c",q[j]);
    puts("");
  }
  return 0;
}
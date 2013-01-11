int main(){
  char p[51];
  int i=0,j,n;
  scanf("%d",&n);
  while(i<n){
    scanf("%s",p);
    for(j=0;j<strlen(p);j++)
      p[j]=p[j]=='Z'?'A':p[j]+1;
    printf("String #%d\n%s\n\n",++i,p);
  }
  return 0;
}
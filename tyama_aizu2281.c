char m[110];int a[101],b[101];
char *T="abcdefghijklmnopqrstuvwxyz";
#define X(n) m[n]=T[(strchr(T,m[n])-T+b[i]-a[i])%26],
main(N,i,c){
  for(;scanf("%d",&N),N;printf("%s\n",m+1)){
    for(scanf("%s",m+1),i=1;i<=N;i++)scanf("%d%d",a+i,b+i);
    for(i=N;i;i--)X(a[i])X(b[i])c=m[a[i]],m[a[i]]=m[b[i]],m[b[i]]=c;
  }
}
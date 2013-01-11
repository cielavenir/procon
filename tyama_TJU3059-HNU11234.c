char t[3][3]={{0,2,1},{1,0,2},{2,1,0}},*x="RPS"; //RPS
main(){
  int n,i,w[3];
  char p,q;
  scanf("%d",&n);
  for(;n;n--){
    memset(w,0,sizeof(w));
    scanf("%d",&i);
    for(;i;i--){
      scanf(" %c",&p);
      scanf(" %c",&q);
      p=strchr(x,p)-x;
      q=strchr(x,q)-x;
      w[t[p][q]]++;
    }
    puts(w[1]>w[2]?"Player 1":w[1]<w[2]?"Player 2":"TIE");
  }
}
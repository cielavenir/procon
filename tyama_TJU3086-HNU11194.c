int index(char *s,int c){char *p=strchr(s,c);return p&&c?p-s:-1;}

solve(char *s){
  char unit[8]="IVXLCDM\0";
  int i=0,_s=strlen(s),r=0,iunit[7]={1,5,10,50,100,500,1000};
  for(;i<_s;i++){
    int x=index(unit,s[i]);
    if(x<index(unit,s[i+1]))r-=iunit[x];else r+=iunit[x];
  }
  printf("%d\n",r);
}

main(){
  char s[20];
  int n;
  scanf("%d",&n);
  for(;n;n--){
    scanf("%s",s);
    solve(s);
  }
}
int main(){
  char s[4];
  int i,n;
  while(1){
    int yes=0,no=0;
    scanf("%d",&n);
    if(!n)return 0;
    for(i=0;i<n;i++){
      scanf("%s",s);
      if(s[0]=='Y')yes++; else no++;
    }
    printf(yes>no ? "Major\n" : yes<no ? "Minor\n" : "Tie\n");
  }
}
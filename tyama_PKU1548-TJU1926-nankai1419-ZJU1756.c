int c[25][25];

int isclean(){
  int x,y;
  for(x=1;x<25;x++)
    for(y=1;y<25;y++)
      if(c[x][y])return 0;
  return 1;
}

void go(){
  int x=1,y=1,i;
  while(y<25){
    for(i=x;i<25;i++) /* i=x+1 is bad in case y++ */
      if(c[i][y]){x=i;c[i][y]=0;break;}
    if(i==25)y++;
  }
}

int main(){
  int x,y,i;
  /*memset(c,0,sizeof(c)); not needed! */
  while(1){
    scanf("%d%d",&x,&y);
    if(x==-1)return 0;
    if(x!=0){c[x][y]=1;continue;}
    /*check*/
    i=0;
    while(!isclean()){
      go();
      i++;
    }
    printf("%d\n",i);
    memset(c,0,sizeof(c));
  }
}
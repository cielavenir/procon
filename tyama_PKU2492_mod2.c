#include <stdio.h>

int x[2001][2001];
int bugs(int b, int i){
  int j,k,l,s,t,f=0,m=1;
  if(i<=1){return 0;}

  /*init*/
  for(k=1;k<=b;k++)
    for(l=1;l<=b;l++)
      x[k][l]=0;
  for(k=1;k<=b;k++)x[k][k]=1;

  /*input*/
  for(j=0;j<i;j++){
    scanf("%d%d",&s,&t);
    if(s==t)f=1;
    if(s<t)
      x[s][t]=1;
    else
      x[t][s]=1;
  }
  if(f)return 1;

  /*•\Œ‹‡*/
  while(1){
    f=0;
    for(k=m+1;k<=b;k++)
      if(x[m][k]&&x[k][k]){ /*Œ‹‡€”õ‚Å‚«‚Ä‚¢‚é*/
        int flag=0;
        f=1;x[k][k]=0;
        flag = x[m][k]==1 ? -1 : 1;
        for(j=k+1;j<=b;j++){
          if(x[k][j]){
            if(x[m][j]==-flag)return 1;
            x[m][j]=flag;
            x[k][j]=0;
          }
        }
      }
    if(!f)m++; /*1‚Æ’¼Ú‚Â‚È‚ª‚Á‚Ä‚¢‚È‚¢‚Ì‚àŒŸõ*/
    if(m==b){
      /*ÅIŠm‚©‚ß*/
      for(t=1;x[t][t];t++);
      for(k=1;k<2;k++)
        for(l=k+1;l<3;l++)
          if(x[k][k]&&x[l][l]){
            int flag=0;
            for(j=t;j<=b;j++){
              if(x[k][j]==1){
                if(x[l][j]==1)flag|=1;
                else if(x[l][j]==-1)flag|=2;
              }else if(x[k][j]==-1){
                if(x[l][j]==-1)flag|=1;
                else if(x[l][j]==1)flag|=2;
              }
              if(flag==3)return 1;
            }
          }
      return 0;
    }
  }
}

int main(){
  int j=1,n,b,i;
  scanf("%d",&n);
  for(;j<=n;j++){
    scanf("%d%d",&b,&i);
    printf("Scenario #%d:\n",j);
    printf(bugs(b,i)?"S":"No s");
    printf("uspicious bugs found!\n\n");
  }
}
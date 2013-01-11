char m[20][21],s[101];
char direc[5]="^v<>";

solve(h,w,n){
  int i,j,x,y,d;
  char *p;
  for(i=0;i<h;i++)
    for(j=0;j<w;j++)
      if(p=strchr(direc,m[i][j])){
        y=i;x=j;
        d=p-direc;
        m[i][j]='.';
        break;
      }
  for(j=0;j<n;j++)
    switch(s[j]){
      case 'U':
        d=0;if(y>0  &&m[y-1][x]=='.')y--;break;
      case 'D':
        d=1;if(y<h-1&&m[y+1][x]=='.')y++;break;
      case 'L':
        d=2;if(x>0  &&m[y][x-1]=='.')x--;break;
      case 'R':
        d=3;if(x<w-1&&m[y][x+1]=='.')x++;break;
      case 'S':
        switch(d){
          case 0:
            for(i=y-1;~i;i--){
              if(m[i][x]=='#')break;
              if(m[i][x]=='*'){m[i][x]='.';break;}
            }break;
          case 1:
            for(i=y+1;i<h;i++){
              if(m[i][x]=='#')break;
              if(m[i][x]=='*'){m[i][x]='.';break;}
            }break;
          case 2:
            for(i=x-1;~i;i--){
              if(m[y][i]=='#')break;
              if(m[y][i]=='*'){m[y][i]='.';break;}
            }break;
          case 3:
            for(i=x+1;i<w;i++){
              if(m[y][i]=='#')break;
              if(m[y][i]=='*'){m[y][i]='.';break;}
            }break;
        }
        break;
    }
  m[y][x]=direc[d];
  for(i=0;i<h;i++)
    printf("%s\n",m[i]);
}

main(){
  int c,h,w,n,i;
  scanf("%d",&c);
  for(;c;c--){
    scanf("%d%d",&h,&w);
    for(i=0;i<h;i++)
      scanf("%s",m[i]);
    scanf("%d%s",&n,s);
    solve(h,w,n);
    if(c>1)puts("");
  }
}
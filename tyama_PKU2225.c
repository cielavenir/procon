#define push(x,y,z) q[f]=(((x)<<16)+((y)<<8)+z),f=(f+1)%80
char m[10][10][11];
int c[10][10][10],s[3],e[3],q[80];
main(i,j,k,n,r,f,g,x,y,z){
  for(;~scanf("%s",m);){
    memset(c,0xff,sizeof(c));
    for(scanf("%d",&n),i=0;i<n;i++)for(j=0;j<n;j++)scanf("%s",m[i][j]);
    scanf("%d%d%d%d%d%d",s+2,s+1,s,e+2,e+1,e);
    for(r=-1,q[0]=(s[0]<<16)+(s[1]<<8)+s[2],f=1,g=0,c[s[0]][s[1]][s[2]]=0;f!=g;){
      x=q[g]>>16,y=(q[g]>>8)&0xf,z=q[g]&0xf;g=(g+1)%80;
      if(x>0&&m[x-1][y][z]!='X'&&c[x-1][y][z]==-1)c[x-1][y][z]=c[x][y][z]+1,push(x-1,y,z);
      if(y>0&&m[x][y-1][z]!='X'&&c[x][y-1][z]==-1)c[x][y-1][z]=c[x][y][z]+1,push(x,y-1,z);
      if(z>0&&m[x][y][z-1]!='X'&&c[x][y][z-1]==-1)c[x][y][z-1]=c[x][y][z]+1,push(x,y,z-1);
      if(x<n-1&&m[x+1][y][z]!='X'&&c[x+1][y][z]==-1)c[x+1][y][z]=c[x][y][z]+1,push(x+1,y,z);
      if(y<n-1&&m[x][y+1][z]!='X'&&c[x][y+1][z]==-1)c[x][y+1][z]=c[x][y][z]+1,push(x,y+1,z);
      if(z<n-1&&m[x][y][z+1]!='X'&&c[x][y][z+1]==-1)c[x][y][z+1]=c[x][y][z]+1,push(x,y,z+1);
      if(~c[e[0]][e[1]][e[2]]){r=c[e[0]][e[1]][e[2]];break;}
    }
    printf(~r?"%d %d\n":"NO ROUTE\n",n,r);
    scanf("%s",m);
  }
}
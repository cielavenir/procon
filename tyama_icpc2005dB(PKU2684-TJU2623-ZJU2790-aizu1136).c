#define I(X,C)\
X##xm=X##ym=9999,X##xM=X##yM=-9999;\
for(scanf("%d",&C),i=0;i<C;i++){\
  scanf("%d%d",X[i],X[i]+1);\
  if(X##xm>X[i][0])X##xm=X[i][0];\
  if(X##ym>X[i][1])X##ym=X[i][1];\
  if(X##xM<X[i][0])X##xM=X[i][0];\
  if(X##yM<X[i][1])X##yM=X[i][1];\
}for(i=0;i<C;i++)X[i][0]-=X##xm,X[i][1]-=X##ym;X##xM-=X##xm,X##yM-=X##ym;

m[10][2],x[10][2],z[10][2],zz[10][2];
rx[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
ry[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
mv[4][2]={{0,0},{0,0},{0,0},{0,0}};

main(N,M,Z,t,i,j,k,mxm,mym,mxM,myM,zxm,zym,zxM,zyM){
  for(;scanf("%d",&N),N;puts("+++++")){
    I(z,Z)
    for(i=0;i<Z;i++)zz[Z-1-i][0]=z[i][0],zz[Z-1-i][1]=z[i][1];
    for(j=0;j<N;j++){
      I(m,M)
      if(M!=Z)continue;
      mv[1][0]=myM,mv[2][0]=mxM,mv[2][1]=myM,mv[3][1]=mxM;
      for(k=0;k<4;k++){
        for(i=0;i<M;i++)x[i][0]=rx[k][0]*m[i][0]+rx[k][1]*m[i][1]+mv[k][0],x[i][1]=ry[k][0]*m[i][0]+ry[k][1]*m[i][1]+mv[k][1];
        if(!memcmp(x,z,4*2*M)||!memcmp(x,zz,4*2*M))printf("%d\n",j+1),k=4;
      }
    }
  }
  return 0;
}
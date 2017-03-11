M[100][200],Z=100,l=100000;main(i,j){
for(M[0][0]=M[0][0+Z]=M[1][1+Z]=M[1][1+Z]=j=1;j<Z;j++)M[0][j+Z]=M[0][j-1+Z];
for(;i<Z;i++)for(M[i][0]=M[i-1][0],j=1;j<Z;j++)M[i][j]=(M[i-1][j]+M[i-1][j-1+Z])%l,M[i][j+Z]=(M[i][j-1+Z]+M[i-1][j-1])%l;
for(;~scanf("%d%d",&i,&j)&&i;)printf("%d\n",(M[i-1][j-1]+M[i-1][j-1+Z])%l);exit(0);}

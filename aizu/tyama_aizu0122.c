p[]={-1,0,1,-2,2,-2,2,-2,2,-1,0,1};
P[]={-2,-2,-2,-1,-1,0,0,1,1,2,2,2};
s[]={-1,0,1,-1,0,1,-1,0,1};
S[]={-1,-1,-1,0,0,0,1,1,1};
m[10],M[10],n;int D(x,y,d){int i=0,j;
for(;i<12;i++)for(j=0;j<9;j++)if(x+p[i]==m[d]+s[j]&&y+P[i]==M[d]+S[j]&&0<=x+p[i]&&x+p[i]<10&&0<=y+P[i]&&y+P[i]<10)if(d==n-1||D(x+p[i],y+P[i],d+1))return 1;
return 0;}
main(X,Y,i){for(;scanf("%d%d%d",&X,&Y,&n)>2;puts(D(X,Y,0)?"OK":"NA"))for(i=0;i<n;i++)scanf("%d%d",m+i,M+i);exit(0);}
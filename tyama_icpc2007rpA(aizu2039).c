#define M 30100
J,T[M],t[M];main(I,i,j,k,L,r){
for(i=2;i<M;i++)if(!T[i])for(j=i*2;j<M;j+=i)T[j]=1;
for(i=2;i<M;i++)if(!T[i])t[J++]=i;
for(;scanf("%d",&L),L;printf("%d\n",r))for(r=I=0;(i=t[I])<L;I++)for(J=I;(j=t[J])<=(k=L-i-j);J++)if(!T[k]&&j-i<k&&k<j+i)r++;
exit(0);}
double M[12][4096],r,t;D[12],n;
double dfs(p,f){if(M[p][f]<0){
int i=0;
for(M[p][f]=0;i<n;i++)if(!(f&1<<i)&&(t=dfs(i,f|1<<i)+D[p]+D[i]-2*sqrt(D[p]*D[i]),M[p][f]<t))M[p][f]=t;
}return M[p][f];}
main(l,i,j,d){for(;~scanf("%d",&l);puts(d-r>l?"NA":"OK")){
for(d=n=0;getchar()-10;d+=D[n++]*2)scanf("%d",D+n);
for(i=0;i<n;i++)for(j=0;j<1<<n;j++)M[i][j]=-1;
for(r=i=0;i<n;)t=dfs(i++,1<<i),r=r>t?r:t;
}exit(0);}
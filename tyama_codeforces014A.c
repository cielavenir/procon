char M[50][51];
main(n,m,a,b,c,d,i){
for(scanf("%d%d",&n,&m),i=0;i<n;i++)scanf("%s",M[i]);
for(a=i=0;i!=-1;a++)for(i=0;i<n;i++)if(M[i][a]=='*'){i=-1;break;}a--;
for(b=m-1,i=0;i!=-1;b--)for(i=0;i<n;i++)if(M[i][b]=='*'){i=-1;break;}b++;
for(c=i=0;i!=-1;c++)for(i=0;i<m;i++)if(M[c][i]=='*'){i=-1;break;}c--;
for(d=n-1,i=0;i!=-1;d--)for(i=0;i<m;i++)if(M[d][i]=='*'){i=-1;break;}d++;
for(;c<=d;puts(""),c++)for(i=a;i<=b;i++)putchar(M[c][i]);
return 0;
}
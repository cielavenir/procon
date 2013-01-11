m,a[9][2],S[2499];
D(d,s){int i=d==m?++S[s]+99:0;for(;i<=a[d][1];i++)D(d+1,s+i**a[d]);}
main(i){for(;scanf("%d",&m),m;){
for(i=0;i<m;i++)scanf("%d%d",a[i],a[i]+1);
memset(S,0,9996);D(0,0);
for(scanf("%d",&i);i;i--)scanf("%d",&m),printf("%d\n",S[m]);
}exit(0);}
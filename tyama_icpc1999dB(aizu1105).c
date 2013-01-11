z[1010000];main(N,a,b,i){for(;scanf("%d%d%d",&N,&a,&b),N;printf("%d\n",a)){
for(memset(z,0,4040000),*z=1,i=0;i<=N;i++)if(z[i])z[a+i]=a+i<=N,z[b+i]=b+i<=N;
for(a=i=0;i<=N;i++)a+=!z[i];
}exit(0);}
a[11],j,x;main(N,i){for(;scanf("%d",&N),j=N;memset(a,0,sizeof(a))){
for(getchar(),i=0;(j=getchar())!='\n';i++)if(j=='M')a[i%N]++;else if(j-'L')a[N]+=a[i%N]+1,a[i%N]=0;else a[i%N]+=a[N]+1,a[N]=0;
for(i=0;i<=N;printf(i<N?"%d ":"%d\n",a[i]),i++)for(j=N-1;j>i;j--)if(a[j]<a[j-1])x=a[j],a[j]=a[j-1],a[j-1]=x;
}}
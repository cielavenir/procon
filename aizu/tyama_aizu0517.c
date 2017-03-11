S[100001];main(n,k,s,t,z){for(;scanf("%d%d",&n,&k)>1&&n;printf("%d\n",k)){
for(t=1;t<=n;t++)S[t]=1;
for(z=0;k;k--)if(scanf("%d",&t),t)S[t]=0;else z++;
for(t=1;t<=n;t++)S[t]+=S[t-1];
for(s=t=0;t<=n;t++){if(S[t]-S[s]>z)s++;if(t-s>k)k=t-s;}
}exit(0);}

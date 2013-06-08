p,q,a,N,c;D(n,d,x,k){if(p*d==q*n)c++;else if(k<N&&p*d>q*n)for(;x*d<=a;x++)D(n*x+d,x*d,x,k+1);}
main(){for(;scanf("%d%d%d%d",&p,&q,&a,&N),N;printf("%d\n",c))D(c=0,1,1,0);exit(0);}
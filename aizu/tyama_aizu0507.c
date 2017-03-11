M[30];D(i,n,d){for(M[d]=d>0&&M[d-1]<n?M[d-1]:n;M[d]>0;M[d]--)if(n>M[d])D(i,n-M[d],d+1);else for(i=0;i<=d;i++)printf(d-i?"%d ":"%d\n",M[i]);}main(n){for(;~scanf("%d",&n)&&n;)D(0,n,0);exit(0);}

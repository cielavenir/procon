int h(a,b){return b?h(b,a%b):a;}
main(s,n,x,b,g){
scanf("%d",&n);
for(s=0,b=2;b<n;b++)for(x=n;x;x/=b)s+=x%b;
g=h(s,n-=2);
printf("%d/%d\n",s/g,n/g);
return 0;
}
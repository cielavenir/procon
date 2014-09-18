s,i,x,r=-999;main(n){for(scanf("%d",&n);n--;){
scanf("%d",&x);
s+=x;
if(r<s)r=s;
if(s<0)s=0;
}x=!printf("%d\n",r);}
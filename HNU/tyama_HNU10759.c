int G(x,y){return y?G(y,x%y):x;}
main(n,a,b){for(;scanf("%d",&n),n;){scanf("%d",&a);for(n--;n;n--){scanf("%d",&b);a=(!a||!b)?0:a/G(a,b)*b;}printf("%d\n",a);}exit(0);}
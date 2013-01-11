g(x,y){return x>y?h(x,y):h(y,x);}
h(x,y){return y?h(y,x%y):x;}
main(x,y){for(;~scanf("%d%d",&x,&y);printf("%d\n",y/g(x,y)));}
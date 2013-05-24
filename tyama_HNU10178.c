int G(x,y){return y?G(y,x%y):x;}
main(x,y){for(gets(&x);~scanf("%d%d",&x,&y);printf("%d\n",G(x,y)));exit(0);}
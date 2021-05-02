int G(x,y){return y?G(y,x%y):x;}
main(i,x,y,g){for(gets(&x);~scanf("%d%d",&x,&y);printf("%d %d %d\n",i++,x/g*y,g))g=G(x,y);}
int G(x,y){return y?G(y,x%y):x;}
a,b,g,t,T;main(){for(scanf("%d",&T);t<T;printf("%d %d %d\n",++t,a/g*b,g=G(a,b)))scanf("%d%d",&a,&b);}
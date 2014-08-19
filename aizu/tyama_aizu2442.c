#define Z(x,i)(x[i]+x[n/2+i])
x[99],y[99],X,Y;
n,i;main(){
	for(gets(x);~scanf("%d %d",x+n,y+n);n++);
	if(!(n&1))for(X=Z(x,0),Y=Z(y,0);++i<n/2&&Z(x,i)==X&&Z(y,i)==Y;);
	printf(i==n/2?"%f %f\n":"NA\n",X/2.0,Y/2.0);exit(0);
}
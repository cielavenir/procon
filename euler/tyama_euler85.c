int a(x){return x<0?-x:x;}
int z(x){return x*(x+1)/2;}
main(x,y,r,R,T,M){
	for(scanf("%d",&T);T--;){
		scanf("%d",&M);
		for(R=r=0,x=1;z(x)<=M;x++){
			for(y=1;z(x)*z(y-1)<=M;y++){
				if(a(M-r)>a(M-z(x)*z(y)) || (a(M-r)==a(M-z(x)*z(y))&&R<x*y))r=z(x)*z(y),R=x*y;
			}
		}
		printf("%d\n",R);
	}
}
// 1 2000000
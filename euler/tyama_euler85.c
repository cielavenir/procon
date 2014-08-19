#define M 2000000
int a(x){return x<0?-x:x;}
int z(x){return x*(x+1)/2;}
main(x,y,r,R){
	for(r=x=1;z(x)<M;x++){
		for(y=1;z(x)*z(y)<M;y++);
		if(a(M-r)>a(M-z(x)*z(y-1)))r=z(x)*z(y-1),R=x*(y-1);
		if(a(M-r)>a(M-z(x)*z(y)))r=z(x)*z(y),R=x*y;
	}
	printf("%d\n",R);
}
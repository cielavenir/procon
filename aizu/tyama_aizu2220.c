#define zero(n)(fabs(n)<.01)
main(n,a,b,c,d,p,q,r,D){
	for(scanf("%d",&n);n;n--){
		scanf("%d%d%d%d",&a,&b,&c,&d);//fx=ax3+bx2+cx+d
		if(a<0)a=-a,b=-b,c=-c,d=-d;   //won't lose generality
		p=3*a,q=2*b,r=c,D=q*q-4*p*r;  //f'x=3ax2+2bx+c D: f'x=0?
		if(D>0){
			double x1=(-q-sqrt(D))/p/2,x2=(-q+sqrt(D))/p/2;
			double y1=a*x1*x1*x1+b*x1*x1+c*x1+d;
			double y2=a*x2*x2*x2+b*x2*x2+c*x2+d;
			if(!zero(y1)&&!zero(y2)&&y1*y2>0)goto one;
			puts(
				zero(x1)?(
					d==0?"1 0":"2 1"
				):zero(x2)?(
					d==0?"0 1":"1 2"
				):x1>0?(
					d>0?"2 1":d<0?"3 0":"2 0"
				):x2<0?(
					d>0?"0 3":d<0?"1 2":"0 2"
				):(
					d>0?"2 1":d<0?"1 2":"1 1"
				)
			);
		}else if(D==0){
			double x=(-q)/p/2;
			double y=a*x*x*x+b*x*x+c*x+d;
			puts(
				zero(y)?(
					d>0?"0 3":d<0?"3 0":"0 0"
				):(
					d>0?"0 1":d<0?"1 0":"0 0"
				)
			);
		}else one:
			puts(d>0?"0 1":d<0?"1 0":"0 0");
	}
	exit(0);
}

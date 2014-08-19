//http://d.hatena.ne.jp/blankblank/20090214/1234541494 - x1y2-y1x2==0 -> OK
main(){
	double a,b,c,d,e,f,g,h;
	for(scanf("%lf",&a);~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f,&g,&h);)
		puts(fabs((c-a)*(h-f)-(d-b)*(g-e))>1e-10?"NO":"YES");
	exit(0);
}
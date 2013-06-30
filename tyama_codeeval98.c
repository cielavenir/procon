main(){double a,b,c,d,e;
	for(;~scanf("Center: (%lf, %lf); Radius: %lf; Point: (%lf, %lf)\n",&a,&b,&c,&d,&e);)a-=d,b-=e,puts(a*a+b*b<c*c?"true":"false");
}
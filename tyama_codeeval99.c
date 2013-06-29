main(){double a,b,c,d;
	for(;~scanf("(%lf, %lf) (%lf, %lf)\n",&a,&b,&c,&d);)printf("%.0f\n",hypot(c-a,d-b));
}
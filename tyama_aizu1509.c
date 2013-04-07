main(r,t,D,a,b,c,d,e,A,B,C){for(;scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&A,&B,&C)>7;printf("%d\n",r)){
	r=a*A+b*B+c*C;
	r=C>=d?a*A+b*B+e*C:(D=d,d-=C,t=B<d?B:d,B-=t,d-=t,t=A<d?A:d,A-=t,d-=t,r>(t=a*A+b*B+e*D))?t:r;
}exit(0);}
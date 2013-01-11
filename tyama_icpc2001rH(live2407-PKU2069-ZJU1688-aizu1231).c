#define Q(x)(x)*(x)
N,i,M;double X[30],Y[30],Z[30],cx,cy,cz,d,m;
double D(i){return sqrt(Q(X[i]-cx)+Q(Y[i]-cy)+Q(Z[i]-cz));}
int L(){for(m=i=0;i<N;i++)if(D(i)>m)m=D(i),M=i;return M;}
main(t){for(;scanf("%d",&N),N;printf("%f\n",D(L()))){
	for(i=0;i<N;i++)scanf("%lf%lf%lf",X+i,Y+i,Z+i);
	for(cx=cy=cz=d=0.5;d>1e-8;d/=2)for(t=0;t<100;t++)i=L(),cx+=(X[i]-cx)*d,cy+=(Y[i]-cy)*d,cz+=(Z[i]-cz)*d;
}exit(0);}
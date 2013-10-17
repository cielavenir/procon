// Solve Ka = (mx)(nx) / (A-x) <=> mnx2 - Kax + KaA = 0 and print log10(1/mx)
main(m,n){double k,a;for(;scanf("%lf%lf%d%d",&k,&a,&m,&n),k;printf("%.3f\n",log10(n*2/(sqrt(k*k+4*m*n*k*a)-k))));}
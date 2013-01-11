//gosasi?

main(T){
  double r,R,H,V,p=3.14159265358979323846264338327950288;
  for(scanf("%d",&T);T;T--)
    scanf("%lf%lf%lf%lf",&r,&R,&H,&V),printf("%.6f\n",(R==r?V/p/r/r:(cbrt(V/p*3/H*(R-r)+r*r*r)-r)/(R-r)*H)+0.0);
  return 0;
}
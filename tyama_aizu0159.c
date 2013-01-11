main(n,i,I){
  for(;scanf("%d",&n),n;){
    double m=999,h,w,z;
    for(;n--;){
      scanf("%d%lf%lf",&i,&h,&w);
      z=fabs(w*10000/h/h-22);
      if(m>z)m=z,I=i;
      else if(m==z&&i<I)I=i;
    }
    printf("%d\n",I);
  }
  return 0;
}
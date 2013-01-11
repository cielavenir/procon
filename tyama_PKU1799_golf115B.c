//r/sin(pi/n)+r=R <=> r=R/(1+1/sin(pi/n))
main(i,n){float R;for(gets(n);~scanf("%f%d",&R,&n);printf("Scenario #%d:\n%.3f\n\n",i++,R/(1+1/sin(3.141592/n))));}
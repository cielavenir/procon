main(n,r,x,y,z,l,w){
  for(;~scanf("%d",&n),n;printf("%d\n",r))
    for(r=0;n;n--){
      scanf("%d%d%d%d",&x,&y,&z,&w),l=x+y+z;
      if(l<=60&&w<=2)r+=600;
      else if(l<=80&&w<=5)r+=800;
      else if(l<=100&&w<=10)r+=1000;
      else if(l<=120&&w<=15)r+=1200;
      else if(l<=140&&w<=20)r+=1400;
      else if(l<=160&&w<=25)r+=1600;
    }
  return 0;
}
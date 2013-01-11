int t[1112];
main(x,y,z,m){
  for(;x<1112;x++)t[x]=x*x*x;
  while(scanf("%d",&z),z){
    for(m=x=1;x<z;x++){
      for(y=1;y<z;y++)
        if(t[x]+t[y]>t[z])break;
      y--;
      if(t[x]+t[y]>m)m=t[x]+t[y];
    }
    printf("%d\n",t[z]-m);
  }
}
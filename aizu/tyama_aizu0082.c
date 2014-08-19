x[]={1,2,1,2,1,4,1,4},o[]={0,2,6,4,1,3,7,5},a[8];
main(i,j,v,V,m,t){for(;;){
for(i=0;i<8;i++)if(scanf("%d",a+i)==-1)exit(0);
for(v=1e9,V=0,i=0;i<8;i++){for(m=j=0;j<8;j++)t=a[j]-x[(o[i]+j)%8],m+=t<0?0:t;if(m<v)v=m,V=o[i];}
for(j=0;j<8;j++)printf(j<7?"%d ":"%d\n",x[(V+j)%8]);
}}
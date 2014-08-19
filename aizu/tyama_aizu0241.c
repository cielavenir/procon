a[4],b[4],m[16];main(n,i,j){for(;scanf("%d",&n),n;){
for(;n--;printf("%d %d %d %d\n",m[0]-m[5]-m[10]-m[15],m[1]+m[4]-m[11]+m[14],m[2]+m[7]+m[8]-m[13],m[3]-m[6]+m[9]+m[12]))
for(scanf("%d%d%d%d%d%d%d%d",a,a+1,a+2,a+3,b,b+1,b+2,b+3),i=0;i<4;i++)for(j=0;j<4;j++)m[i+j*4]=a[i]*b[j];
}exit(0);}
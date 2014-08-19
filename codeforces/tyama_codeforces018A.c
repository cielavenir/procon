#define adj(a,b,c,d) ((a-c)*(a-c)+(b-d)*(b-d))
#define tri(a,b,c,d,e,f) (adj(a,b,c,d)>0&&adj(c,d,e,f)>0&&adj(a,b,c,d)+adj(c,d,e,f)==adj(e,f,a,b))
#define judge(a,b,c,d,e,f) (tri(a,b,c,d,e,f)||tri(c,d,e,f,a,b)||tri(e,f,a,b,c,d))
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},a[6];
main(i,j){
  scanf("%d%d%d%d%d%d",a,a+1,a+2,a+3,a+4,a+5);
  if(judge(a[0],a[1],a[2],a[3],a[4],a[5]))puts("RIGHT"),exit(0);
  for(i=0;i<3;i++)for(j=0;j<4;j++){
    a[2*i]+=dx[j],a[2*i+1]+=dy[j];
    if(judge(a[0],a[1],a[2],a[3],a[4],a[5]))puts("ALMOST"),exit(0);
    a[2*i]-=dx[j],a[2*i+1]-=dy[j];
  }
  puts("NEITHER"),exit(0);
}
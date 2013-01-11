#include <stdio.h>
#define between(a,x,b) (((a)<=(x))&&((x)<=(b)))

int calary(const int y){
    if(y%4)return 0;
	if(!(y%400)) return 1;
	if(!(y%100)) return 0;
	return 1;
}

int getdate(int m,int d,int y){
  int a[13]={-1,31,0,31,30,31,30,31,31,30,31,30,31},r=0,i=0;
  a[2] = calary(y) ? 29 : 28;
  for(;i<m;i++)r+=a[i];
  return r+d-1;
}

int q(int y){return calary(y) ? 366 : 365;}

void calc(int m,int d,int y,int m0, int d0){
  int dy=getdate(m,d,y)+q(y-1);
  int x[3]={getdate(m0,d0,y-1),getdate(m0,d0,y)+q(y-1),getdate(m0,d0,y+1)+q(y-1)+q(y)};
  int c,di;

  if(between(-7, di = x[0] - dy, 7))
    {printf("%d/%d/%d IS %d DAY%s PRIOR\n",m0,d0,y-1,abs(di),abs(di)==1?"":"S");return;}
  if(between(-7, di = x[2] - dy, 7))
    {printf("%d/%d/%d IS %d DAY%s AFTER\n",m0,d0,y+1,abs(di),abs(di)==1?"":"S");return;}
  if(between(-7, di = x[1] - dy, 7)){
    if(di==0){printf("SAME DAY\n");return;}
    if(di<0){printf("%d/%d/%d IS %d DAY%s PRIOR\n",m0,d0,y,abs(di),abs(di)==1?"":"S");return;}
    printf("%d/%d/%d IS %d DAY%s AFTER\n",m0,d0,y,abs(di),abs(di)==1?"":"S");return;
  }
  printf("OUT OF RANGE\n");

}

int main(){
  int i,n;
  int m,d,y,m0,d0;
  scanf("%d\n",&n);
  for(i=0;i<n;){
    scanf("%d/%d/%d %d/%d",&m,&d,&y,&m0,&d0);
    printf("%d ",++i);
    calc(m,d,y,m0,d0);
  }
  return 0;
}
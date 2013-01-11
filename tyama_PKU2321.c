#include <math.h>

int _x[100];
double x[10][10];
double p[10];
double _p[10];
int n;

void output(){
  int i=0;
  for(;i<n;i++){
    if(i)printf(" ");
    printf("%.5f",p[i]);
  }
  printf("\n");
}

int main(){
  int i,j,k,a,s;
  double d;
  for(n=0;;n++){
    if(scanf("%d",&a)<=0)break;
    _x[n]=a;
  }
  n=(int)sqrt(n);
  for(i=0;i<n;i++){
    s=0;
    for(j=0;j<n;j++)s+=_x[i*n+j];
    for(j=0;j<n;j++)x[i][j]=_x[i*n+j]*1.0/s;
  }
  
  p[0]=1.0;output();
  for(i=0;i<9;i++){
    memcpy(_p,p,sizeof(p));
    for(j=0;j<n;j++){
      d=0.0;
      for(k=0;k<n;k++){
      d+=x[k][j]*_p[k];
      }
      p[j]=d;
    }
    output();
  }
  return 0;
}
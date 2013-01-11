#include <iostream>
#include <cmath>
using namespace std;

int parse(int m, int y){
  int t, c, i, dm=0;
  double r;
  cin >> t >> r >> c;//scanf("%d%lf%d",&t,&r,&c);
  if(t){ //fukuri
    for(i=0;i<y;i++){
      dm=(int)floor(r*m);
      m=m+dm-c;
    }
  }else{ //tanri
    for(i=0;i<y;i++){
      dm+=(int)floor(r*m);
      m=m-c;
    }
    m+=dm;
  }
  return m;
}

void data(){
  int m,y,n,i,r;
  cin >> m >> y >> n;//scanf("%d%d%d",&m,&y,&n);
  r=m;
  for(i=0;i<n;i++){
    int x=parse(m,y);
    if(x>r)r=x;
  }
  cout << r << endl;//printf("%d\n",r);
}

int main(){
  int i,n;
  cin >> n;//scanf("%d",&n);
  for(i=0;i<n;i++)data();
  return 0;
}
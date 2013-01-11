#include <iostream>
#include <vector>
#include <cfloat> //VC
#include <cmath> //GCC

using namespace std;
#define MAX 12

#ifdef _MSC_VER
#define max(a,b) ( (a)>(b)?(a):(b) )
#define min(a,b) ( (a)<(b)?(a):(b) )
#define finite _finite
#endif

int c[MAX][MAX];

class Straw{
  protected:
  int x1, x2, y1,y2;
  public:
  Straw(int a, int b, int c, int d){
    x1=a,y1=b,x2=c,y2=d;
  }
  int connect(Straw *s){
    if(this->x1>s->x2||this->x2<s->x1)return false;
    int x1=max(this->x1,s->x1);
    int x2=min(this->x2,s->x2);
    float n=((float)(this->y2-this->y1))/(this->x2-this->x1);
    float m=((float)(s->y2-s->y1))/(s->x2-s->x1);
    float ny1=finite(n) ? n*(x1-this->x1)+this->y1: this->y1;
    float ny2=finite(n) ? n*(x2-this->x1)+this->y1: this->y2;
    float my1=finite(m) ? m*(x1-s->x1)+s->y1 : s->y1;
    float my2=finite(m) ? m*(x2-s->x1)+s->y1 : s->y2;
    //cout << x1 << " " << x2 << " " << n << " " << m << " " << ny1 << " " << my1 << " " << ny2 << " " << my2 << endl;
    if(this->x1==this->x2&&s->x1==s->x2){
      if(this->x1!=s->x1)return 0;
      //cout << this->y1 << " " << this->y2 << " " << s->y1 << " " << s->y2 << endl;
      if(max(this->y1,this->y2)>=min(s->y1,s->y2) || max(s->y1,s->y2)>=min(this->y1,this->y2))return 1;
      return 0;
    }
    return (ny1-my1)*(ny2-my2)<=0 ? 1 : 0;
  }
};

bool check(int a, int b, int n){
  int v[MAX],x,i,j;
  for(i=0;i<n;i++)v[i]=0;
  v[a]=1;
  do{
    x=0;
    for(i=0;i<n;i++)
      for(j=0;j<n;j++){
        if(v[i]&&!v[j]&&c[i][j]){
          if(j==b)return true;
          v[j]=1;x++;
        }
      }
  }while(x);
  return false;
}

int main(){
  int n,i,j,x1,x2,y1,y2,a,b;
  vector<Straw*> v;
  while(true){
    cin >> n;
    if(!n)return 0;
    
    //わらを確認
    for(i=0;i<n;i++){
      cin >> x1 >> y1 >> x2 >> y2;
      v.push_back(x1 < x2 ? new Straw(x1,y1,x2,y2) : new Straw(x2,y2,x1,y1));
    }
    
    //それぞれつながっているか
    for(i=0;i<n;i++)
      for(j=0;j<n;j++){
        c[i][j]=v[i]->connect(v[j]);
        //cout << i << j << c[i][j] << endl ;
      }
    
    //メモリ清掃
    for(i=0;i<n;i++)
      delete v[i];
    v.clear();
    
    //接続チェック
    while(cin >> a >> b&&a&&b){
      const char *s=(a==b||check(a-1,b-1,n))?"CONNECTED":"NOT CONNECTED";
      cout << s << endl;
    }
  }
}
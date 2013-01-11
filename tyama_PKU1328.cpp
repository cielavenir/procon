#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cmath>
using namespace std;

#define x first
#define y second
#define adjacent(a,b) sqrt((a)*(a)-(b)*(b))

int main(){
 int c=1,n,r,x,y,f;
 vector< pair<int,int> > v;
 for(;scanf("%d%d",&n,&r),n;c++){
   f=0;v.clear();
   printf("Case %d: ",c);

   //input
   for(;n;n--){
     scanf("%d%d",&x,&y);
     if(y>r)f=1;
     v.push_back(make_pair(x,y));
   }
   if(f){puts("-1");continue;}
   sort(v.begin(),v.end());

   //check
   while(v.size()){
     double a=adjacent(r,v[0].y),m=v[0].x-a,M=v[0].x+a;
     v.erase(v.begin());
     while(v.size()){
       a=adjacent(r,v[0].y);
       double m2=v[0].x-a,M2=v[0].x+a;
       m=max(m,m2);
       M=min(M,M2);
       if(M<m)break;
       v.erase(v.begin());
     }
     n++;
   }
   printf("%d\n",n);
 }
 return 0;
}
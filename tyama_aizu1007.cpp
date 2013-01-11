#include<vector>
#include<algorithm>
#include<cstdio>
#define Z{vector<int>b;for(j=0;j<i;j++)b.push_back(x++);if(c)reverse(b.begin(),b.end());c^=1;a.push_back(b);}
using namespace std;main(){for(int t=1,x,c,n,i,j;scanf("%d",&n),n;){
vector<vector<int> >a;
for(printf("Case %d:\n",t++),x=c=i=1;i<=n;i++)Z
for(i-=2;i;i--)Z
for(i=0;i<n;puts(""),i++)for(j=0;j<n;j++)printf("%3d",a[i+j][0]),a[i+j].erase(a[i+j].begin());
}}
#include<cstdio>
#include<set>
#define M(x,y)std::make_pair(x,y)
typedef std::set<std::pair<int,int> >S;
int n,m,x,y,X,Y,d,D;main(){for(;~scanf("%d",&n)&&n;printf("%d\n",n)){
S s;S::iterator i,I;
for(;n;n--)scanf("%d%d",&x,&y),s.insert(M(x,y));
for(i=s.begin();i!=s.end();i++)for(x=i->first,y=i->second,I=i;++I!=s.end();)if(X=I->first,Y=I->second,d=X-x,D=Y-y,m=d*d+D*D,m>n&&s.find(M(x-D,y+d))!=s.end()&&s.find(M(X-D,Y+d))!=s.end())n=m;
}}

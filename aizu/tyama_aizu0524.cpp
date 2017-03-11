#include<cstdio>
#include<set>
#include<vector>
using namespace std;
#define M(x,y)make_pair(x,y)
typedef set<pair<int,int> >S;
int n,i,x,y,X,Y;main(){for(;~scanf("%d",&n)&&n;){
vector<pair<int,int> >v;
for(scanf("%d%d",&X,&Y);--n;)scanf("%d%d",&x,&y),v.push_back(M(x-X,y-Y));
S s;S::iterator I;
for(scanf("%d",&n);n;n--)scanf("%d%d",&x,&y),s.insert(M(x,y));
for(I=s.begin();I!=s.end();I++){
	for(x=I->first,y=I->second,i=0;i<v.size();i++)
		if(s.find(M(x+v[i].first,y+v[i].second))==s.end())break;
	if(i==v.size()){
		printf("%d %d\n",x-X,y-Y);
		I=s.end();
		break;
	}
}
}}

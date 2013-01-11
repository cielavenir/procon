#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
char M[9];
int main(){
	int T,P,R,t,p,s,m,i;
	for(;scanf("%d%d%d",&T,&P,&R),R;){
		map<int,map<int,int> >z;
		for(i=0;i<R;i++){
			scanf("%d%d%d%s",&t,&p,&s,M);
			if(*M=='W')z[t][p]-=1;else z[t][p]=s-z[t][p]*1200;
		}
		vector<pair<int,pair<int,int> > >v;
		for(i=1;i<=T;i++){
			for(p=s=0,R=1;R<=P;R++)if(z[i][R]>0)p++,s+=z[i][R];
			v.push_back(make_pair(-p,make_pair(s,i)));
		}
		sort(v.begin(),v.end());
		for(i=0;i<T;i++)printf("%d %d %d\n",v[i].second.second,-v[i].first,v[i].second.first);
	}
}
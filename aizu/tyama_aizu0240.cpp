#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int n,y,b,r,t,j;
	for(;scanf("%d%d",&n,&y),n;){
		vector<pair<double,int> >v;
		for(;n--;){
			scanf("%d%d%d",&b,&r,&t);
			if(t==1)v.push_back(make_pair(1+y*r/100.0,b));
			else{
				double d=1;
				for(j=0;j<y;j++)d*=1+r/100.0;
				v.push_back(make_pair(d,b));
			}
		}
		sort(v.begin(),v.end());
		printf("%d\n",v[v.size()-1].second);
	}
}
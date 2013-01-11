#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int x,n,m,k,i,r;
	for(;scanf("%d",&n),n;printf("%d\n",r)){
		vector<set<int> >v;
		for(i=0;i<n;i++){
			set<int>s;
			for(scanf("%d",&m),k=0;k<m;k++)scanf("%d",&x),s.insert(x);
			v.push_back(s);
		}
		set<int>t;
		for(scanf("%d",&k),m=0;m<k;m++)scanf("%d",&x),t.insert(x);
		for(r=-1,k=0;k<n;k++){
			set<int>s;
			set_intersection(v[k].begin(),v[k].end(),t.begin(),t.end(),inserter(s,s.end()));
			if(s.size()==t.size()){if(~r){r=-1;break;}r=k+1;}
		}
	}
}
#include <vector>
#include <cstdio>
using namespace std;
vector<pair<pair<int,int>,int> >m;
vector<int> result;
int result_size=-1;
int n,x;
void dfs(vector<int>&v,int d){
	if(d==n){
		int i=0,j,w;
		for(i=0;i<m.size();i++){
			for(w=0,j=m[i].first.first;j<=m[i].first.second;j++){
				w+=v[j];
			}
			if(m[i].second!=w)break;
		}
		if(i==m.size()){
			for(w=i=0;i<n;i++)w+=v[i];
			if(w>result_size)result_size=w,result=v;
		}
	}else{
		for(int i=0;i<=x;i++){
			v.push_back(i);
			dfs(v,d+1);
			v.pop_back();
		}
	}
}
main(){
	int M,l,r,s;
	for(scanf("%d%d%d",&n,&x,&M);M--;){
		scanf("%d%d%d",&l,&r,&s);
		m.push_back(make_pair(make_pair(l-1,r-1),s));
	}
	vector<int>v;
	dfs(v,0);
	if(result_size==-1){puts("-1");return 0;}
	printf("%d",result[0]);
	for(M=1;M<n;M++)printf(" %d",result[M]);
	puts("");
}
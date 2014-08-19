#include <map>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int i,n,x;
	for(;scanf("%d",&n),n;){
		vector<int>v,u;
		for(i=0;i<n;i++)scanf("%d",&x),v.push_back(x);
		for(x=0;;x++){
			u.clear();
			map<int,int>m;
			for(i=0;i<n;i++)m[v[i]]++;
			for(i=0;i<n;i++)u.push_back(m[v[i]]);
			if(v==u)break;
			v=u;
		}
		printf("%d\n%d",x,u[0]);
		for(i=1;i<n;i++)printf(" %d",u[i]);
		puts("");
	}
}
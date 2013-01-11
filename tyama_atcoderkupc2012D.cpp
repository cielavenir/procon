#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
	vector<pair<int,int> >v;
	int N,M,a,b,i=0,s=1,t=0,r=0;
	for(scanf("%d%d",&N,&M),i=0;i<M;i++)
		scanf("%d%d",&a,&b),v.push_back(make_pair(a,b));
	sort(v.begin(),v.end());
	for(i=0;i<M;i++){
		if(v[i].first>s){
			if(v[i].first-t>1||t<s){
				puts("Impossible");
				return 0;
			}
			if(t==N){
				printf("%d\n",r+1);
				return 0;
			}
			s=t+1;r++;
		}
		if(t<v[i].second)t=v[i].second;
	}
	if(t==N){
		printf("%d\n",r+1);
		return 0;
	}
	puts("Impossible");
}
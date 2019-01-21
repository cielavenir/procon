#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;
int main(){
	int n,m;
	scanf("%d",&n);
	vector<pii> data(n);
	for(int i=0;i<n;i++){
		int x,w;
		scanf("%d%d",&x,&w);
		data[i]=make_pair(x-w,x+w);
	}
	sort(data.begin(),data.end(),[](const pii &a,const pii &b){return a.second<b.second;});
	int r=0,f=-2e9;
	for(int i=0;i<data.size();i++){
		if(data[i].first>=f){
			r++;
			f=data[i].second;
		}
	}
	printf("%d\n",r);
}

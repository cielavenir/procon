#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	vector<int>v(3);
	scanf("%d%d%d",&v[0],&v[1],&v[2]);
	sort(v.begin(),v.end());
	int r=0;
	for(;;){
		if(v[0]&&v[1]&&v[2]){
			v[1]-=v[0];
			v[2]-=v[0];
			r+=v[0];
			v[0]=0;
		}else if(v[2]>=2){
			v[0]=1,v[2]-=2;
		}else break;
		sort(v.begin(),v.end());
	}
	printf("%d\n",r);
}
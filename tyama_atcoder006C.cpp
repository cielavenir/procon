#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int a,n,i=0,j,r=0;
	vector<int>v;
	vector<vector<int> >u;
	scanf("%d",&n);
	for(;i<n;i++){
		scanf("%d",&a),v.push_back(a);
		vector<int>_u;u.push_back(_u);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(u[j].size()==0||u[j][u[j].size()-1]>=v[i]){
				u[j].push_back(v[i]);
				r = r < j ? j : r;
				break;
			}
		}
	}
	printf("%d\n",r+1);
}
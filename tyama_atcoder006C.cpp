#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int a,n,i=0,j,r=0;

	scanf("%d",&n);
	vector<int>v(n);
	vector<vector<int> >u(n);
	for(;i<n;i++)scanf("%d",&a),v[i]=a;
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
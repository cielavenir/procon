#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int n,i,r=0,b;
	scanf("%d",&n);
	vector<int>A(n),B(n);
	for(i=0;i<n;i++)scanf("%d",&A[i]);
	for(i=0;i<n;i++)scanf("%d",&B[i]);
	for(b=0;b<29;b++){
		int r0=0,t=1<<b;
		vector<int>a;
		transform(A.begin(),A.end(),back_inserter(a),
			[&](int e){return -(e%(2*t));}
		);
		sort(a.begin(),a.end());
		for(auto &e_:B){
			int e=e_%(2*t),sgn=-1,q;
			for(q=1;q<=4;sgn=-sgn,q++){
				r0+=sgn*distance(a.begin(),upper_bound(a.begin(),a.end(),-q*t+e));
			}
		}
		r^=(r0&1)*t;
	}
	printf("%d\n",r);
}

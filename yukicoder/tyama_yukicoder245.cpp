#include <vector>
#include <complex>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cfloat>
using namespace std;
typedef long long val_t;
typedef complex<val_t> P;
typedef vector<P> VP;

val_t cross(const P &a,const P &b){return (conj(a)*b).imag();}
val_t dot(const P &a,const P &b){return (conj(a)*b).real();}
bool intersectLS(const VP &l, const VP &s) {
	return cross(l[1]-l[0], s[0]-l[0])*       // s[0] is left of l
		cross(l[1]-l[0], s[1]-l[0]) <= 0; // s[1] is right of l
}
int main(){
	int n;
	scanf("%d",&n);
	vector<VP> lst(n);
	for(int i=0;i<n;i++){
		long long sx,sy,ex,ey;
		scanf("%lld%lld%lld%lld",&sx,&sy,&ex,&ey);
		lst[i]={P(sx,sy),P(ex,ey)};
	}
	int R=1;
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
		vector<VP> x={{lst[i][0],lst[j][0]},{lst[i][1],lst[j][0]},{lst[i][0],lst[j][1]},{lst[i][1],lst[j][1]}};
		for(auto &e:x){
			if(e[0]==e[1])continue; //bah!!!
			int r=0;
			for(int k=0;k<n;k++)r+=intersectLS(e,lst[k]);
			if(R<r)R=r;
		}
	}
	printf("%d\n",R);
}
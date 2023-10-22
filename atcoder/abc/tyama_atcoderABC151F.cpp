#include <complex>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef double coor;
typedef complex<coor> P;
typedef vector<P> G;
P minimal_circle(G &l, double &R){
int t,i,k;
	R=0;
	P p, c;
	double move = 1, r;
	for(p=l[0];move>1e-16;move/=2)for(t=0;t<100;t++){
		for(R=i=0;i<l.size();i++)if((r=norm(l[i]-p))>R)R=r,c=p,k=i;
		p+=(l[k]-p)*move;
	}
	return p;
}

int main(){
	int n,x,y;
	G poly;
	double R;
	for(scanf("%d",&n);n--;poly.emplace_back(x,y))scanf("%d %d",&x,&y);
	minimal_circle(poly, R);
	printf("%.15f\n",sqrt(R));
	return 0;
}

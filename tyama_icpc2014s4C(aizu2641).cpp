#include <vector>
#include <cstdio>
using namespace std;

typedef struct{
	double x;
	double y;
	double z;
	double r;
	long long l;
}_object;

int main(){
	int N,Q;
	scanf("%d%d",&N,&Q);
	vector<_object> object(N);
	for(int i=0;i<N;i++)scanf("%lf%lf%lf%lf%lld",&object[i].x,&object[i].y,&object[i].z,&object[i].r,&object[i].l);
	for(int i=0;i<Q;i++){
		// http://www.infra.kochi-tech.ac.jp/takagi/Survey2/7Parameter.pdf
		double xa,ya,za,xx,yx,zx;
		scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&za,&xx,&yx,&zx);
		double vx=xx-xa,vy=yx-ya,vz=zx-za;
		long long R=0;
		for(auto &e:object){
			double t=(vx*(e.x-xa)+vy*(e.y-ya)+vz*(e.z-za))/(vx*vx+vy*vy+vz*vz);
			if(t<0)t=0;
			if(t>1)t=1;
			double xt=xa+vx*t,yt=ya+vy*t,zt=za+vz*t;
			double r=(e.x-xt)*(e.x-xt)+(e.y-yt)*(e.y-yt)+(e.z-zt)*(e.z-zt);
			if(r<e.r*e.r+1e-9)R+=e.l;
		}
		printf("%lld\n",R);
	}
}
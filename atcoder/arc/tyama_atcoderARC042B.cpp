#include <complex>
#include <vector>
#include <cstdio>
#include <cfloat>
using namespace std;
const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};
P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}
double distanceLP(const L &l, const P &p) {
  return abs(p - projection(l, p));
}


int main(){
	double x,y;
	int N;
	scanf("%lf%lf%d",&x,&y,&N);
	P p(x,y);
	vector<P> poly(N);
	for(int i=0;i<N;i++){
		scanf("%lf%lf",&x,&y);
		poly[i]=P(x,y);
	}
	double r=DBL_MAX;
	for(int i=0;i<N;i++){
		r=min(r,distanceLP(L(poly[i],poly[(i+1)%N]),p));
	}
	printf("%f\n",r);
}
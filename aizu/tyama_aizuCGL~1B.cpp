#include <complex>
#include <vector>
#include <cstdio>
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

typedef vector<P> G;

struct C {
  P p; double r;
  C(const P &p, double r) : p(p), r(r) { }
};

int main(){
	double x,y;
	int q;
	scanf("%lf%lf",&x,&y);P p0(x,y);
	scanf("%lf%lf%d",&x,&y,&q);P p1(x,y);
	for(;q--;){
		scanf("%lf%lf",&x,&y);P p(x,y);
		P t=(p1-p0)*dot(p1-p0,p-p0)/norm(p1-p0)+p0;
		P s=p+(t-p)*2.0;
		printf("%.9f %.9f\n",real(s),imag(s));
	}
}
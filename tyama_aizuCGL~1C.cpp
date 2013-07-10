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

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;                               // a--c--b on line
}

const char *z[]={"ONLINE_FRONT","CLOCKWISE","ON_SEGMENT","COUNTER_CLOCKWISE","ONLINE_BACK"};
int main(){
	double x,y;
	int q;
	scanf("%lf%lf",&x,&y);P p0(x,y);
	scanf("%lf%lf%d",&x,&y,&q);P p1(x,y);
	for(;q--;){
		scanf("%lf%lf",&x,&y);P p(x,y);
		puts(z[ccw(p0,p1,p)+2]);
	}
}
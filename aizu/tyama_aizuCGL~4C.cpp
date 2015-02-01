#include <complex>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cassert>
using namespace std;
typedef double number;

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<number> P;
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
P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

typedef vector<P> G;

#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
G convex_cut(const G& p, const L& l) {
  G Q;
  for (int i = 0; i < p.size(); ++i) {
    P A = curr(p, i), B = next(p, i);
    if (ccw(l[0], l[1], A) != -1) Q.push_back(A);
    if (ccw(l[0], l[1], A)*ccw(l[0], l[1], B) < 0)
      Q.push_back(crosspoint(L(A, B), l));
  }
  return Q;
}

number area2(const G& P) {
  number A = 0;
  for (int i = 0; i < P.size(); ++i) 
    A += cross(curr(P, i), next(P, i));
  return A;
}

int main(){
	G poly;
	P p;
	int n;
	double x1,y1,x2,y2;
	for(scanf("%d",&n);n--;poly.push_back(p))scanf("%lf%lf",&x1,&y1),p=P(x1,y1);
	for(scanf("%d",&n);n--;){
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		L l(P(x1,y1),P(x2,y2));
		G cut=convex_cut(poly,l);
		printf("%f\n",area2(cut)/2);
	}
}
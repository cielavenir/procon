#include <vector>
#include <complex>
#include <cstdio>
#include <cassert>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

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

P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}

int main(){
	int T,x1,y1,x2,y2;
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		L A(P(x1,y1),P(x2,y2));
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		L B(P(x1,y1),P(x2,y2));
		P r=crosspoint(A,B);
		printf("%.9f %.9f\n",real(r),imag(r));
	}
}
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

typedef vector<P> G;

#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
enum { OUT, ON, IN };
int contains(const G& poly, const P& p) {
  bool in = false;
  for (int i = 0; i < poly.size(); ++i) {
    P a = curr(poly,i) - p, b = next(poly,i) - p;
    if (imag(a) > imag(b)) swap(a, b);
    if (imag(a) <= 0 && 0 < imag(b))
      if (cross(a, b) < 0) in = !in;
    if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
  }
  return in ? IN : OUT;
}

int main(){
	G poly;
	P p;
	int n;
	double x,y;
	for(scanf("%d",&n);n--;poly.push_back(p))scanf("%lf%lf",&x,&y),p=P(x,y);
	for(scanf("%d",&n);n--;printf("%d\n",contains(poly,p)))scanf("%lf%lf",&x,&y),p=P(x,y);
}
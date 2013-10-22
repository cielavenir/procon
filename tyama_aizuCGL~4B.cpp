#include <complex>
#include <vector>
#include <algorithm>
#include <cstdio>
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

typedef vector<P> G;

#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
#define diff(P, i) (next(P, i) - curr(P, i))
number convex_diameter(const G &pt) {
  const int n = pt.size();
  int is = 0, js = 0;
  for (int i = 1; i < n; ++i) {
    if (imag(pt[i]) > imag(pt[is])) is = i;
    if (imag(pt[i]) < imag(pt[js])) js = i;
  }
  number maxd = norm(pt[is]-pt[js]);

  int i, maxi, j, maxj;
  i = maxi = is;
  j = maxj = js;
  do {
    if (cross(diff(pt,i), diff(pt,j)) >= 0) j = (j+1) % n;
    else i = (i+1) % n;
    if (norm(pt[i]-pt[j]) > maxd) {
      maxd = norm(pt[i]-pt[j]);
      maxi = i; maxj = j;
    }
  } while (i != is || j != js);
  return maxd; /* farthest pair is (maxi, maxj). */
}

int main(){
	G poly;
	P p;
	int n;
	double x,y;
	for(scanf("%d",&n);n--;poly.push_back(p))scanf("%lf%lf",&x,&y),p=P(x,y);
	printf("%f\n",sqrt(convex_diameter(poly)));
}
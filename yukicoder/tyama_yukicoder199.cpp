#include <complex>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef int coor;

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<coor> P;
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

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return 0;       // c--a--b on line
  if (norm(b) < norm(c)) return 0;       // a--b--c on line
  return 0;
}

typedef vector<P> G;

vector<P> convex_hull(vector<P> &ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector<P> ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}

int main(){
	G poly;
	P p;
	int n=5;
	double x,y;
	for(;n--;poly.push_back(p))scanf("%lf%lf",&x,&y),p=P(x,y);
	poly=convex_hull(poly);
	puts(poly.size()==5?"YES":"NO");
}
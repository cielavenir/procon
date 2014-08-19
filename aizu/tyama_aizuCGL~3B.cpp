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

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

typedef vector<P> G;

#define curr(P, i) P[(i+1) % P.size()]
#define next(P, i) P[(i+2) % P.size()]
#define prev(P, i) P[(i) % P.size()]
bool isconvex(const G &P){
  for(int i = 0; i < P.size(); ++i){
    int d=ccw(prev(P, i), curr(P, i), next(P, i));
    if(d==-1) return false;
  }
  return true;
}

int main(){
	G poly;
	P p;
	int n;
	double x,y;
	for(scanf("%d",&n);n--;poly.push_back(p))scanf("%lf%lf",&x,&y),p=P(x,y);
	printf("%d\n",isconvex(poly));
}
#include <vector>
#include <complex>
#include <cstdio>
using namespace std;

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
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
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}
bool intersectSS(const L &s, const L &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
         ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}

int main(){
	double x,y;
	scanf("%lf%lf",&x,&y);
	P a(x,y);
	scanf("%lf%lf",&x,&y);
	P b(x,y);
	L l(a,b);
	int N;
	scanf("%d",&N);
	vector<P> poly(N);
	for(int i=0;i<N;i++){
		scanf("%lf%lf",&x,&y);
		poly[i]={x,y};
	}
	int r=0;
	for(int i=0;i<N;i++){
		L m(poly[i],poly[(i+1)%N]);
		r+=intersectSS(l,m);
	}
	printf("%d\n",r/2+1);
}
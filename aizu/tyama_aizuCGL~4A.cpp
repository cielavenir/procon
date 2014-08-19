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
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return +2;       // a--b--c on line
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
	int n;
	double x,y;
	for(scanf("%d",&n);n--;poly.push_back(p))scanf("%lf%lf",&x,&y),p=P(x,y);
	poly=convex_hull(poly);
	x=99999,y=99999;
	int idx=0;
	for(n=0;n<poly.size();n++){
		if(y>(int)imag(poly[n]))x=99999,y=(int)imag(poly[n]);
		if(y==(int)imag(poly[n])&&x>(int)real(poly[n]))x=(int)real(poly[n]),idx=n;
	}
	rotate(poly.begin(),poly.begin()+idx,poly.end());
	printf("%d\n",poly.size());
	for(n=0;n<poly.size();n++)printf("%d %d\n",(int)real(poly[n]),(int)imag(poly[n]));
}
//cf: codeiq2944

#include <iostream>
#include <string>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;

typedef double number;
typedef complex<number> point;

/// http://www.prefield.com/algorithm/geometry/convex_intersect.html ///

namespace std {
  bool operator < (const point& a, const point& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
number cross(const point& a, const point& b) {
  return imag(conj(a)*b);
  //return a.real()*b.imag()-a.imag()*b.real();
}
number dot(const point& a, const point& b) {
  return real(conj(a)*b);
  //return a.real()*b.real()+a.imag()*b.imag();
}

typedef vector<point> polygon;

#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
enum { OUT, IN, ON };
int contains(const polygon& P, const point& p) {
  bool in = false;
  for (int i = 0; i < P.size(); ++i) {
    point a = curr(P,i) - p, b = next(P,i) - p;
    if (imag(a) > imag(b)) swap(a, b);
    if (imag(a) <= number(0) && number(0) < imag(b))
      if (cross(a, b) < number(0)) in = !in;
    if (cross(a, b) == number(0) && dot(a, b) <= number(0)) return ON;
  }
  return in ? IN : OUT;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	polygon lake(n);
	for(int i=0;i<n;i++){
		double a,b;
		cin>>a>>b;
		lake[i]=point(a,b);
	}
	for(cin>>n;n--;){
		double a,b;
		cin>>a>>b;
		point p(a,b);
		cout<<contains(lake,p)<<endl;
	}
}

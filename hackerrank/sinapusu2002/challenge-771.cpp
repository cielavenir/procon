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
enum { OUT, ON, IN };
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

bool intersect_1pt(const point& a, const point& b,
                   const point& c, const point& d, point &r) {
  number D =  cross(b - a, d - c);
  if(D==number(0)) return false;
  number t =  cross(c - a, d - c) / D;
  number s = -cross(a - c, b - a) / D;
  r = a + t * (b - a);
  return t>=number(0) && t<=number(1) && s>=number(0) && s<=number(1);
}
polygon convex_intersect(const polygon &P, const polygon &Q) {
  const int n = P.size(), m = Q.size();
  int a = 0, b = 0, aa = 0, ba = 0;
  enum { Pin, Qin, Unknown } in = Unknown;
  polygon R;
  do {
    int a1 = (a+n-1) % n, b1 = (b+m-1) % m;
    number C = cross(P[a] - P[a1], Q[b] - Q[b1]);
    number A = cross(P[a1] - Q[b], P[a] - Q[b]);
    number B = cross(Q[b1] - P[a], Q[b] - P[a]);
    point r;
    if (intersect_1pt(P[a1], P[a], Q[b1], Q[b], r)) {
      if (in == Unknown) aa = ba = 0;
      R.push_back( r );
      in = B > number(0) ? Pin : A > number(0) ? Qin : in;
    }
    if (C == number(0) && B == number(0) && A == number(0)) {
      if (in == Pin) { b = (b + 1) % m; ++ba; }
      else           { a = (a + 1) % m; ++aa; }
    } else if (C >= number(0)) {
      if (A > number(0)) { if (in == Pin) R.push_back(P[a]); a = (a+1)%n; ++aa; }
      else       { if (in == Qin) R.push_back(Q[b]); b = (b+1)%m; ++ba; }
    } else {
      if (B > number(0)) { if (in == Qin) R.push_back(Q[b]); b = (b+1)%m; ++ba; }
      else       { if (in == Pin) R.push_back(P[a]); a = (a+1)%n; ++aa; }
    }
  } while ( (aa < n || ba < m) && aa < 2*n && ba < 2*m );
  if (in == Unknown) {
    if (contains(Q, P[0])) return P;
    if (contains(P, Q[0])) return Q;
  }
  return R;
}

number area2(const polygon& P) {
  number A = 0;
  for (int i = 0; i < P.size(); ++i) 
    A += cross(curr(P, i), next(P, i));
  return A;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	for(cin>>n;n--;){
		vector<long long>v(12);
		for(auto &e:v)cin>>e;

		polygon poly1={
			point(v[0],v[1]),point(v[2],v[3]),point(v[4],v[5])
		},poly2={
			point(v[6],v[7]),point(v[8],v[9]),point(v[10],v[11])
		};
		//maybe not CCW
		if(cross(poly1[1]-poly1[0],poly1[2]-poly1[0])<number(0)){
			swap(poly1[1],poly1[2]);
		}
		if(cross(poly2[1]-poly2[0],poly2[2]-poly2[0])<number(0)){
			swap(poly2[1],poly2[2]);
		}
		polygon poly3=convex_intersect(poly1,poly2);
		cout<<poly3.size()<<endl;
		for(int i=poly3.size()-1;i>=0;i--){
			if(poly3[i]==poly3[(i+1)%poly3.size()])poly3.erase(poly3.begin()+i);
		}
		for(int i=poly3.size()-1;i>=0;i--){
			if(cross(
				poly3[(i+poly3.size()-1)%poly3.size()]-poly3[i],
				poly3[(i+1)%poly3.size()]-poly3[i]
			)==number(0))poly3.erase(poly3.begin()+i);
		}

		number n=area2(poly3);
		cout<<n/2<<endl;
	}
}

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
bool on_line(const P& a, const L& l){
  return dot(l[0]-a,l[1]-a)<EPS;
}

P crosspoint(const L &l, const L &m) throw(bool){
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) throw(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}

int main(){
	int x1,y1,x2,y2;
	for(;~scanf("%d%d%d%d",&x1,&y1,&x2,&y2),x1||y1||x2||y2;){
		try{
			L A(P(x1,y1),P(x2,y2));
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			L B(P(x1,y1),P(x2,y2));
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			L C(P(x1,y1),P(x2,y2));
			P a=crosspoint(A,B),b=crosspoint(B,C),c=crosspoint(C,A);
			if(!on_line(a,A)||!on_line(a,B)||!on_line(b,B)||!on_line(b,C)||!on_line(c,C)||!on_line(c,A)){puts("kyo");continue;}
			double s=abs(cross(a,b)+cross(b,c)+cross(c,a))/2;
			if(s<EPS)puts("kyo");
			else if(s<100000)puts("syo-kichi");
			else if(s<1000000)puts("kichi");
			else if(s<1900000)puts("chu-kichi");
			else puts("dai-kichi");
		}catch(bool e){puts("kyo");}
	}
}
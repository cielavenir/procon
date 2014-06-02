#include <complex>
#include <vector>
#include <algorithm>
#include <cstdio>
  
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
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
  
number closestPair(G &p) {
  int n = p.size(), s = 0, t = 1, m = 2;
  int S[n];
  S[0] = 0, S[1] = 1;
  sort(ALL(p)); // "p < q" <=> "p.x < q.x"
  double d = abs(p[s]-p[t]);
  for (int i = 2; i < n; S[m]=i,i++,m++) REP(j, m) {
    if (abs(p[S[j]]-p[i])<d) s = S[j], t = i, d = abs(p[s]-p[t]);
    if (real(p[S[j]]) < real(p[i]) - d) m--,S[j]=S[m],j--;
  }
  return abs(p[s]-p[t]);//make_pair( p[s], p[t] );
}
  
int main(){
	G poly;
	int n;
	double x,y;
	for(scanf("%d",&n);n--;poly.push_back(P(x,y)))scanf("%lf%lf",&x,&y);
	printf("%.9f\n",closestPair(poly));
}
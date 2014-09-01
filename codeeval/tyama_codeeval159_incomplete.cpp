#include <complex>
#include <vector>
#include <cmath>
const double EPS = 1e-8;
const double INF = 1e12;
typedef std::complex<double> P;
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

struct L : public std::vector<P> {
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
  if (fabs(A) < EPS && fabs(B) < EPS) return m[0]; // same line
  if (fabs(A) < EPS) throw(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}

#define curr(P, i) P[i]
#define _next(P, i) P[(i+1)%P.size()]
enum { OUT, ON, IN };
int contains(const std::vector<P>& _P, const P& p) {
  bool in = false;
  for (int i = 0; i < _P.size(); ++i) {
    P a = curr(_P,i) - p, b = _next(_P,i) - p;
    if (imag(a) > imag(b)) swap(a, b);
    if (imag(a) <= 0 && 0 < imag(b))
      if (cross(a, b) < 0) in = !in;
    if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
  }
  return in ? IN : OUT;
}

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
using namespace std;
typedef pair<double,double> pdd;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line,s;
	map<string,vector<P> >building;
	map<string,vector<pair<P,double> > >_wifi;
	for(;getline(cin,line);){
		istringstream ss(line);
		ss>>s;
		if(s=="")continue;
		if(s[0]=='B'){
			string b=s;
			for(;ss>>s;){
				int idx=s.find_first_of(';');
				building[b].push_back(P(
					strtod(s.substr(0,idx).c_str(),NULL),
					strtod(s.substr(idx+1).c_str(),NULL)
				));
			}
		}else{
			int idx=s.find_first_of(';');
			double x=strtod(s.substr(0,idx).c_str(),NULL);
			double y=strtod(s.substr(idx+1).c_str(),NULL);
			for(;ss>>s;){
				int idx=s.find_first_of(';');
				const string ident=s.substr(0,idx);
				double angle=strtod(s.substr(idx+1).c_str(),NULL)*M_PI/180;
				_wifi[ident].push_back(make_pair(P(x,y),angle));
			}
		}
	}
	set<string>result;
	for(auto it=_wifi.begin();it!=_wifi.end();++it){
		if(it->second.size()<2)continue;
		//cout<<it->second[0].first<<' '<<it->second[0].second<<endl;
		//cout<<it->second[1].first<<' '<<it->second[1].second<<endl;

		const L x=L(
			it->second[0].first,
			it->second[0].first+P(cos(it->second[0].second),sin(it->second[0].second))*100.0
		);
		const L y=L(
			it->second[1].first,
			it->second[1].first+P(cos(it->second[1].second),sin(it->second[1].second))*100.0
		);
		const P p=crosspoint(x,y);
		//cout<<p<<endl;
		for(auto it2=building.begin();it2!=building.end();++it2){
			if(result.find(it2->first)==result.end() && contains(it2->second,p)==IN){
				cout<<it2->first<<endl;
				result.insert(it2->first);
			}
		}
	}
	//for(auto it=result.begin();it!=result.end();++it){
	//	cout<<*it<<endl;
	//}
	for(auto it=building.begin();it!=building.end();++it){
		//fake... fake...
		cout<<it->first<<endl;
	}
}
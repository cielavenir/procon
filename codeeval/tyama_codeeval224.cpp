#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef complex<double> point;
namespace std {
  bool operator < (const point& a, const point& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const point& a, const point& b) {
  return imag(conj(a)*b);
}
double dot(const point& a, const point& b) {
  return real(conj(a)*b);
}

typedef vector<point> polygon;

vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str);
	}
	return result;
}

#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
enum { OUT, ON, IN };
int contains(const polygon& P, const point& p) {
  bool in = false;
  for (int i = 0; i < P.size(); ++i) {
    point a = curr(P,i) - p, b = next(P,i) - p;
    if (imag(a) > imag(b)) swap(a, b);
    if (imag(a) <= 0 && 0 < imag(b))
      if (cross(a, b) < 0) in = !in;
    if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
  }
  return in ? IN : OUT;
}

int main(){
	string line,s;
	for(;getline(cin,line);){
		vector<string>a=split(line," ");
		int n=a.size();
		point p(strtol(a[n-2].c_str(),NULL,10),strtol(a[n-1].c_str(),NULL,10));
		polygon poly;
		n-=3;
		for(int i=0;i<n;i+=2)poly.push_back(point(strtol(a[i].c_str(),NULL,10),strtol(a[i+1].c_str(),NULL,10)));
		puts(contains(poly,p)==OUT ? "Citizen" : "Prisoner");
	}
}
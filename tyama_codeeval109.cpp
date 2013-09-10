#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <complex>
using namespace std;

//sited from spaghetti source
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

//main
vector<L> lines;
vector<int> max_comb;
void dfs(vector<int> &comb,int cur){ //enumerate combination
	if(comb.size()>max_comb.size())max_comb=comb;
	int j;
	for(;cur<lines.size();cur++){
		for(j=0;j<comb.size();j++)if(intersectSS(lines[cur],lines[comb[j]]))break;
		if(j==comb.size()){
			comb.push_back(cur);
			dfs(comb,cur+1);
			comb.pop_back();
		}
	}
}
main(){
	double x1,x2,y1,y2;
	string s;
	for(;getline(cin,s);){
		int idx=s.find_first_of("[");
		s=s.substr(idx);
		replace(s.begin(),s.end(),'[',' ');
		replace(s.begin(),s.end(),']',' ');
		replace(s.begin(),s.end(),',',' ');
		replace(s.begin(),s.end(),')',' ');
		istringstream ss(s);
		ss>>x1>>y1>>x2>>y2;
		lines.push_back(L(P(x1,y1),P(x2,y2)));
	}
	vector<int> comb;
	for(int cur=0;cur<lines.size();cur++){
		comb.push_back(cur);
		dfs(comb,cur+1);
		comb.pop_back();
	}
	for(int i=0;i<max_comb.size();i++){
		cout<<max_comb[i]+1<<endl;
	}
}
/*
1: ([37.788353, -122.387695], [37.829853, -122.294312])
2: ([37.429615, -122.087631], [37.487391, -122.018967])
3: ([37.474858, -122.131577], [37.529332, -122.056046])
4: ([37.532599, -122.218094], [37.615863, -122.097244])
5: ([37.516262, -122.198181], [37.653383, -122.151489])
6: ([37.504824, -122.181702], [37.633266, -122.121964])
7: ([37.548812, -122.066735], [37.417236, -122.069544])
8: ([37.791923, -122.259789], [37.705751, -122.335478])
9: ([37.780195, -122.246685], [37.694985, -122.325498])
10: ([37.770312, -122.233194], [37.6894812, -122.314682])
11: ([37.820133, -122.285405], [37.677656, -122.310521])
12: ([37.808315, -122.276112], [37.669581, -122.297764])
13: ([37.773842, -122.238571], [37.719448, -122.349218])
14: ([37.763822, -122.224489], [37.730276, -122.359075])
15: ([37.763822, -122.224489], [37.730276, -122.359075]) 
*/
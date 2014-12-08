#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <complex>
#include <cstdio>
#include <cmath>
using namespace std;

//union_find
class union_find{
	int *parent,n;
public:
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	union_find(int _n){
		n=_n;
		parent=new int[n];
		for(int i=0;i<n;i++)parent[i]=i;
	}
	~union_find(){delete []parent;}
	int unite(int a,int b){
		int x=root(a),y=root(b);if(x==y)return 0;
		parent[y]=x;
		return 1;
	}
};

//farthest pair (from spaghetti source)
typedef int number;
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
int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if (cross(b, c) > 0)   return +1;       // counter clockwise
	if (cross(b, c) < 0)   return -1;       // clockwise
	if (dot(b, c) < 0)     return +2;       // c--a--b on line
	if (norm(b) < norm(c)) return -2;       // a--b--c on line
	return 0;
}
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
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
#define diff(P, i) (next(P, i) - curr(P, i))
number convex_diameter(const vector<P> &pt) {
	const int n = pt.size();
	int is = 0, js = 0;
	for (int i = 1; i < n; ++i) {
		if (imag(pt[i]) > imag(pt[is])) is = i;
		if (imag(pt[i]) < imag(pt[js])) js = i;
	}
	number maxd = norm(pt[is]-pt[js]);
	int i, maxi, j, maxj;
	i = maxi = is;
	j = maxj = js;
	do {
		if (cross(diff(pt,i), diff(pt,j)) > 0) j = (j+1) % n; //fixme: cross==0?
		else i = (i+1) % n;
		if (norm(pt[i]-pt[j]) > maxd) {
			maxd = norm(pt[i]-pt[j]);
			maxi = i; maxj = j;
		}
	} while (i != is || j != js);
	return maxd;
}

int main(){
	int N;
	scanf("%d",&N);
	if(N==0){
		puts("1");
		return 0;
	}

	unordered_map<int,vector<P> >z;
	{
		unordered_set<int>kind_x,kind_y;
		
		vector<pair<int,int> >v(N);
		for(int i=0;i<N;i++){
			scanf("%d%d",&v[i].first,&v[i].second);
			kind_x.insert(v[i].first);
			kind_y.insert(v[i].second);
		}
		if(kind_x.size()<kind_y.size()*5)for(int i=0;i<N;i++)swap(v[i].first,v[i].second);
		sort(v.begin(),v.end());
		union_find uf(N);
		for(int i=0;i<N-1;i++){
			int upper=upper_bound(v.begin(),v.end(),make_pair(v[i].first+10,9999999))-v.begin();
			for(int j=i+1;j<upper;j++){
				if(
					(v[i].first-v[j].first)*(v[i].first-v[j].first) + (v[i].second-v[j].second)*(v[i].second-v[j].second)
				<=100)uf.unite(i,j);
			}
		}
		for(int i=0;i<N;i++){
			int r=uf.root(i);
			z[r].push_back(complex<number>(v[i].first,v[i].second));
		}
	}
	number result=0;
	for(auto &it:z){
		auto hull=convex_hull(it.second);
		if(hull.size()<2)continue;
		result=max(result,convex_diameter(hull));
	}
	printf("%.9f\n",sqrt(result)+2);
}
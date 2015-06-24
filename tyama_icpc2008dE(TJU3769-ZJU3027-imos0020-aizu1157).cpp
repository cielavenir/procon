// cpp_range (generic range class, very small equivalent of boost::irange)
// (C) @cielavenir under Boost Software License.
// note: end position is exclusive.

#include <iterator>
template<typename T>
class range{
public:
	struct iterator{
		const T a,b;
		T p;
		const long long d; //because T might be unsigned.
		iterator(T _a,T _b,T _p,long long _d=1):a(_a),b(_b),p(_p),d(_d){}

	public:
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef std::ptrdiff_t difference_type;
		typedef std::random_access_iterator_tag iterator_category;

		//copy
		iterator(const iterator &other):a(other.a),b(other.b),p(other.p),d(other.d){}
		iterator operator=(const iterator &other){return iterator(other.a,other.b,other.p,other.d);}

		//advance
		iterator& operator+=(T n){p+=n*d;return *this;}
		iterator& operator-=(T n){return *this+=(-n);}
		iterator& operator++(){return *this+=1;}
		iterator& operator--(){return *this-=1;}
		iterator operator+(T n) const{return iterator(a,b,p+n*d);}
		iterator operator-(T n) const{return *this+(-n);}

		//difference
		T operator-(const iterator& other) const{return p-other.p;}

		//equality
		bool operator==(const iterator& other) const{return a==other.a && b==other.b && d==other.d && p==other.p;}
		bool operator!=(const iterator& other) const{return !(*this==other);}

		//compare
		bool operator<(const iterator& other) const{return a==other.a && b==other.b && d==other.d && p*d<other.p*d;}
		bool operator>(const iterator& other) const{return a==other.a && b==other.b && d==other.d && p*d>other.p*d;}

		//reference
		const T& operator*() const{return p;}
	};

private:
	const T a,b;
	T siz;
	long long d;
public:
	range(T _a,T _b,long long _d=1):a(_a),b(_b){
		d=_d;
		d=d==0?1:d; //
		siz=( (d>0?(b-a):(a-b)) - 1)  / (d>0?d:-d);
	}

	T operator[](T n){return a+n*d;}
	iterator begin(){return iterator(a,a+d*siz,a,d);}
	iterator end(){return iterator(a,a+d*siz,a+d*(siz+1),d);}
	iterator rbegin(){return iterator(b-d*siz,b,b,-1*d);}
	iterator rend(){return iterator(b-d*siz,b,b-d*(siz+1),-1*d);}
	T size(){return siz;}
};
template<typename T>
range<T> make_range(T a,T b,long long d=1){return range<T>(a,b,d);}

#include <vector>
#include <complex>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cfloat>
using namespace std;
typedef double val_t;
typedef complex<val_t> P;
typedef vector<P> VP;
const val_t EPS=1e-9;

val_t cross(const P &a,const P &b){return (conj(a)*b).imag();}
val_t dot(const P &a,const P &b){return (conj(a)*b).real();}
P projection(const VP &l,const P &p){
	P t=dot(p-l[0],l[0]-l[1])/norm(l[0]-l[1]);
	return l[0]+t*(l[0]-l[1]);
}
bool intersectSP(const VP &s,const P &p){
	return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}
val_t distanceSP(const VP &s,const P &p){
	P r=projection(s,p);
	return intersectSP(s,r) ? abs(r-p) : min(abs(s[0]-p),abs(s[1]-p));
}
bool intersectSS(const VP &l,const VP &m){
	val_t a=cross(l[1]-l[0],m[1]-m[0]);
	val_t b=cross(l[1]-l[0],l[1]-m[0]);
	//VP pt=abs(a)<EPS ? abs(b)<EPS ? {l[0],l[1],m[0],m[1]} : VP() : {m[0]+b/a*(m[1]-m[0])};
	VP pt=vector<VP>{{l[0],l[1],m[0],m[1]},{},{m[0]+b/a*(m[1]-m[0])}}[abs(a)<EPS?abs(b)<EPS?0:1:2];
	return accumulate(pt.begin(),pt.end(),false,[&](bool S,const P &e){
		return S||(dot(l[0]-e,l[1]-e)<EPS && dot(m[0]-e,m[1]-e)<EPS);
	});
}
val_t distanceSS(const VP &s,const VP &t){
	return intersectSS(s,t) ? 0 : min(
		accumulate(s.begin(),s.end(),DBL_MAX,[&](val_t S,const P &e){return min(S,distanceSP(t,e));}),
		accumulate(t.begin(),t.end(),DBL_MAX,[&](val_t S,const P &e){return min(S,distanceSP(s,e));})
	);
}
int main(){
	int n;
	for(;scanf("%d",&n),n;){
		double sx,sy,ex,ey;
		scanf("%lf%lf%lf%lf",&sx,&sy,&ex,&ey);
		VP s={P(sx,sy),P(ex,ey)};
		auto ra0=make_range(0,n);
		printf("%f\n",accumulate(ra0.begin(),ra0.end(),DBL_MAX,[&](val_t S,int _)->val_t{
			int f=0;
			double x1,y1,x2,y2,h;
			scanf("%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&h);
			VP a;
			for(auto &x:{x1,x2})for(auto &y:{y1,y2})a.emplace_back(x,y);
			swap(a[2],a[3]);
			auto ra1=make_range(0,4);
			val_t d=accumulate(ra1.begin(),ra1.end(),DBL_MAX,[&](val_t S,int i){
				f+=cross(a[i]-s[0],a[(i+1)%4]-s[0])<EPS;
				return min(S,distanceSS(s,{a[i],a[(i+1)%4]}));
			});
			return min(S,
				f==4 ? 0 : //inside
				d>h ? (h*h+d*d)/h/2 :
				d
			);
		}));
	}
}
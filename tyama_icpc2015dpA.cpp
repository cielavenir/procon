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
		if(d==0)d=1; //
		siz=( (d>0?(b-a):(a-b)) - 1)  / (d>0?d:-d);
	}

	T operator[](T n){return a+n*d;}
	iterator begin(){return iterator(a,a+d*siz,a,d);}
	iterator end(){return iterator(a,a+d*siz,a+d*(siz+1),d);}
	iterator rbegin(){return iterator(b-d*siz,b,b,-1*d);}
	iterator rend(){return iterator(b-d*siz,b,b-d*(siz+1),-1*d);}
	T size(){return siz+1;}
};

#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cmath>

int main(){
	int a,b;
	for(;scanf("%d%d",&a,&b),a;){
		range<int>ra(0,a/2+2);
		std::vector<double>l(ra.size());
		std::transform(ra.begin(),ra.end(),l.begin(),[&](int i){return fabs(b-hypot(i,a-i));});
		printf("%f\n",*std::min_element(l.begin(),l.end()));
	}
}
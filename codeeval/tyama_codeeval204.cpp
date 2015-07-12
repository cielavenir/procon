#include <iostream>
#include <string>
#include <complex>
#include <vector>
#include <set>
#include <tuple>
#include <cstdio>
using namespace std;

typedef complex<int> P;
double cross(const P& a, const P& b){
	return imag(conj(a)*b);
}
long long gcd2(long long x,long long y){return y?gcd2(y,x%y):x;}
long long gcd(long long x,long long y){
	if(x<0)x=-x;
	if(y<0)y=-y;
	return gcd2(x,y);
}

template<typename I>
tuple<I,I,I> line_equation_int(const complex<I> &A,const complex<I> &B){
	I a=imag(B)-imag(A);
	I b=real(A)-real(B);
	I c=-real(A)*a-imag(A)*b;
	I g=gcd(a,gcd(b,c));
	a/=g,b/=g,c/=g;
	if(a<0 || (a==0&&b<0))a=-a,b=-b,c=-c;
	return make_tuple(a,b,c);
}
template<typename T>
tuple<T,T,T> line_equation_real(const complex<T> &A,const complex<T> &B){
	T a=imag(B)-imag(A);
	T b=real(A)-real(B);
	T c=-real(A)*a-imag(A)*b;
	if(a<0 || (a==0&&b<0))a=-a,b=-b,c=-c;
	return make_tuple(a,b,c);
}

int main(){
	string line;
	for(;getline(cin,line);){
		vector<P>poly;
		set<tuple<int,int,int> >used;
		{
			string s;
			int x,y;
			istringstream ss(line);
			ss>>x>>y;
			poly.emplace_back(x,y);
			for(;ss>>s>>x>>y;){
				poly.emplace_back(x,y);
			}
		}
		int N=poly.size();
		int r=0;
		for(int i=0;i<N-2;i++)for(int j=i+1;j<N-1;j++)for(int k=j+1;k<N;k++){
			if(cross(poly[i]-poly[k],poly[j]-poly[k])==0){
				auto t=line_equation_int(poly[i],poly[j]);
				r += used.find(t)==used.end();
				used.insert(t);
			}
		}
		printf("%d\n",r);
	}
}
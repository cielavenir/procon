#include <tuple>
#include <vector>
#include <complex>
#include <cstdio>
using namespace std;
typedef complex<double> P;
typedef tuple<double,double,double> tddd;
double dot(const P& a, const P& b) {
	return real(conj(a)*b);
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
	int N,M;
	for(;scanf("%d",&N),N;){
		vector<tddd> v(N);
		for(int i=0;i<N;i++){
			double x,y,r;
			scanf("%lf%lf%lf",&x,&y,&r);
			v[i]=make_tuple(x,y,r);
		}
		for(scanf("%d",&M);M--;){
			double x1,y1,x2,y2;
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			P A(x1,y1),B(x2,y2);
			auto t=line_equation_real(A,B);
			double a=get<0>(t);
			double b=get<1>(t);
			double c=get<2>(t);
			double nrm=a*a+b*b;
			for(auto &e:v){
				double d=a*get<0>(e)+b*get<1>(e)+c;
				double x=sqrt(get<2>(e)*get<2>(e)*nrm-d*d);
				P X(get<0>(e) + (-a*d+b*x)/nrm,get<1>(e) + (-b*d-a*x)/nrm);
				P Y(get<0>(e) + (-a*d-b*x)/nrm,get<1>(e) + (-b*d+a*x)/nrm);
				if((dot(X-A,B-A)>0&&dot(X-B,A-B)>0) || (dot(Y-A,B-A)>0&&dot(Y-B,A-B)>0)){
					puts("Safe");
					goto NEXT;
				}
			}
			puts("Danger");
			NEXT:;
		}
	}
}
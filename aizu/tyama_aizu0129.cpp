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
			double a=y2-y1;
			double b=-x2+x1;
			double c=-y1*b-x1*a;
			for(auto &e:v){
				double d=a*get<0>(e)+b*get<1>(e)+c;
				double x=sqrt(get<2>(e)*get<2>(e)*(a*a+b*b)-d*d);
				P X(get<0>(e) + (-a*d+b*x)/(a*a+b*b),get<1>(e) + (-b*d-a*x)/(a*a+b*b));
				P Y(get<0>(e) + (-a*d-b*x)/(a*a+b*b),get<1>(e) + (-b*d+a*x)/(a*a+b*b));
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
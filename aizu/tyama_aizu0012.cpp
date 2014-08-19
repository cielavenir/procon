#include <complex>
#include <cstdio>
using namespace std;
typedef complex<double> P;
double cross(const P& a, const P& b) {
	return imag(conj(a)*b);
}
bool in_triangle(const P& p1,const P& p2,const P& p3,const P& p){
	return cross(p2-p1,p-p1)>0 && cross(p3-p2,p-p2)>0 && cross(p1-p3,p-p3)>0;
}
int main(){
	double x1,y1,x2,y2,x3,y3,x,y;
	for(;~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x,&y);){
		P p1(x1,y1),p2(x2,y2),p3(x3,y3),p(x,y);
		bool in=in_triangle(p1,p2,p3,p)||in_triangle(p2,p1,p3,p);
		puts(in?"YES":"NO");
	}
}
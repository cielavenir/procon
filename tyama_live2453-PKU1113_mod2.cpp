#include <complex>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

typedef complex<int> point;
double cross(const point& a, const point& b) {
	return imag(conj(a)*b);
}
#define curr(P, i) P[(i) % P.size()]
#define next(P, i) P[(i+1) % P.size()]
#define prev(P, i) P[(i-1+P.size()) % P.size()]

int main(){
	int N,L;
	scanf("%d%d",&N,&L);
	vector<point>v(N);
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[i]=point(a,b);
	}
	for(int i=0,z=0,s=N;z<s;){
		if(cross(curr(v,i)-prev(v,i),next(v,i)-curr(v,i))<0)i=(i+1)%v.size(),z++;
		else{
			v.erase(v.begin()+i);i=(i)%v.size();z=0;s--;
		}
	}
	double d=0;
	for(int i=0;i<v.size();i++){
		point p=next(v,i)-curr(v,i);
		d+=hypot(real(p),imag(p));
	}
	printf("%d\n",(int)(0.5+d+2*L*3.14159));
	return 0;
}
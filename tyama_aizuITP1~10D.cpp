#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

double dist(vector<double> &v, int n){
	if(n==-1){
		double r=v[0];
		for(int i=1;i<v.size();i++)r=max(r,v[i]);
		return r;
	}
	double s=0;
	for(int i=0;i<v.size();i++)s+=pow(v[i],n);
	return pow(s,1.0/n);
}
int main(){
	int n;
	scanf("%d",&n);
	vector<double> a(n),b(n);
	for(int i=0;i<n;i++)scanf("%lf",&a[i]);
	for(int i=0;i<n;i++)scanf("%lf",&b[i]);
	for(int i=0;i<n;i++)a[i]=fabs(a[i]-b[i]);
	printf("%f\n%f\n%f\n%f\n",dist(a,1),dist(a,2),dist(a,3),dist(a,-1));
}
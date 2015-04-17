#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	vector<vector<double> >m(N+1);
	for(int i=0;i<=N;i++){
		m[i].resize(3);
		scanf("%lf%lf%lf",&m[i][0],&m[i][1],&m[i][2]);
	}
	double R=0;
	for(int a=1;a<=N;a++)for(int b=a+1;b<=N;b++)for(int c=b+1;c<=N;c++){{{
		double A=(m[b][1]-m[a][1])*(m[c][2]-m[a][2])-(m[c][1]-m[a][1])*(m[b][2]-m[a][2]);
		double B=(m[b][2]-m[a][2])*(m[c][0]-m[a][0])-(m[c][2]-m[a][2])*(m[b][0]-m[a][0]);
		double C=(m[b][0]-m[a][0])*(m[c][1]-m[a][1])-(m[c][0]-m[a][0])*(m[b][1]-m[a][1]);
		double D=-(A*m[a][0]+B*m[a][1]+C*m[a][2]);
		double E=(A*m[0][0]+B*m[0][1]+C*m[0][2]+D);
		R+=sqrt(E*E/(A*A+B*B+C*C));
	}}}
	printf("%.9f\n",R);
}
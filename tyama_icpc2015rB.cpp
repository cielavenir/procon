#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	int N;double d;
	scanf("%d%lf",&N,&d);
	vector<pair<double,double> >v={{d,d}};
	//半径の和**2-高さ(半径)の差**2 == 設置点の差**2
	for(int i=1;i<N;i++){
		scanf("%lf",&d);
		vector<double>a(i);
		transform(v.begin(),v.end(),a.begin(),[&](const pair<double,double> &e)->double{
			return sqrt((e.first+d)*(e.first+d) - (e.first-d)*(e.first-d)) + e.second;
		});
		v.emplace_back(d,max(d,*max_element(a.begin(),a.end())));
	}
	vector<double>a(N);
	transform(v.begin(),v.end(),a.begin(),[&](const pair<double,double> &e)->double{
		return e.first+e.second;
	});
	printf("%f\n",*max_element(a.begin(),a.end()));
}
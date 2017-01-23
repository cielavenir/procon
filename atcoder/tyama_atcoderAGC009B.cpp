#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

map<int,vector<int>>H;
int f(int i){
	vector<int>a;
	for(auto &e:H[i])a.push_back(-f(e));
	sort(a.begin(),a.end());
	int r=0;
	for(int i=1;i<=a.size();i++)r=max(r,i-a[i-1]);
	return r;
}
 
int main(){
	int N,a;
	scanf("%d",&N);
	for(int i=2;i<=N;i++)scanf("%d",&a),H[a].push_back(i);
	printf("%d\n",f(1));
}

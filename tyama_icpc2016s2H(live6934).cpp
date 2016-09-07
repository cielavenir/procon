#include <map>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;

map<int,set<int>>next={
	{1,{1,2,3,4,5,6,7,8,9,0}},
	{2,{2,3,5,6,8,9,0}},
	{3,{3,6,9}},
	{4,{4,5,6,7,8,9,0}},
	{5,{5,6,8,9,0}},
	{6,{6,9}},
	{7,{7,8,9,0}},
	{8,{8,9,0}},
	{9,{9}},
	{0,{0}},
};
bool chk(int n){
	if(n<10)return true;
	auto &e=::next[n/10%10];
	return e.find(n%10)!=e.end() && chk(n/10);
}
int main(){
	vector<int>v;
	for(int i=0;i<300;i++)if(chk(i))v.push_back(i);
	int x;
	for(scanf("%d",&x);~scanf("%d",&x);){
		int idx=lower_bound(v.begin(),v.end(),x)-v.begin();
		int a=x-v[idx-1],b=v[idx]-x;
		printf("%d\n",a<b ? v[idx-1] : v[idx]);
	}
}
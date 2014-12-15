#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int solve(vector<int>&v){
	map<int,int>m;
	for(int i=0;i<v.size();i++)m[v[i]]++;
	vector<int>x;
	for(map<int,int>::iterator it=m.begin();it!=m.end();++it){
		x.push_back(it->second);
	}
	sort(x.begin(),x.end(),greater<int>());
	if(x[0]==3&&x[1]==2)return 5;
	if(x[0]==4)return 4;
	if(x[0]==3)return 3;
	if(x[0]==2&&x[1]==2)return 2;
	if(x[0]==2)return 1;
	return 0;
}

int main(){
	int N;
	for(;scanf("%d",&N),N;){
		int r=0;
		for(;N--;){
			vector<int>v(5);
			for(int i=0;i<5;i++)scanf("%d",&v[i]);
			r=max(r,solve(v));
		}
		printf("%d\n",r);
	}
}
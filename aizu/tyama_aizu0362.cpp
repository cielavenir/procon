#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool chk(const vector<int> &v){
	int s=0;
	for(int i=0;i<v.size();i++){
		if(s<i)return false;
		s=max(s,i+v[i]/10);
	}
	return true;
}

int main(){
	int n;
	scanf("%d",&n);
	vector<int>v(n);
	for(int i=0;i<n;i++)scanf("%d",&v[i]);
	if(chk(v)){
		reverse(v.begin(),v.end());
		if(chk(v)){
			puts("yes");
			return 0;
		}
	}
	puts("no");
}

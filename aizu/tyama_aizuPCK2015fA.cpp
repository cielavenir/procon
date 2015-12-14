#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main(){
	int n,i;
	vector<pair<int,int> >v(6);
	for(i=0;i<6;i++){
		scanf("%d%d",&v[i].first,&v[i].second);
		if(v[i].first>v[i].second)swap(v[i].first,v[i].second);
	}
	sort(v.begin(),v.end());
	puts(v[0]==v[1] && v[2]==v[3] && v[4]==v[5] ? "yes" : "no");
}
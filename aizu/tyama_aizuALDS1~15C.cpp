#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;
int main(){
	vector<pii> data;
	int i1,i2;
	for(scanf("%d",&i1);~scanf("%d%d",&i1,&i2);)data.emplace_back(i1,i2);
	sort(data.begin(),data.end(),[](const pii &a,const pii &b){return a.second<b.second;});
	int f=0,r=0;
	for(int i=0;i<data.size();i++){
		if(data[i].first>f){ //終端は閉区間。開区間なら>=になる。
			r++;
			f=data[i].second;
		}
	}
	printf("%d\n",r);
}
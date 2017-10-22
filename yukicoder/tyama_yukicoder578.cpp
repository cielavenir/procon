#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<pii> data(m);
	for(int i=0;i<m;i++){
		int i1,i2,i3,i4,i5,i6;
		scanf("%d %d:%d %d %d:%d",&i1,&i2,&i3,&i4,&i5,&i6);
		data[i]=make_pair(i1*1440+i2*60+i3,i4*1440+i5*60+i6);
	}
	sort(data.begin(),data.end(),[](const pii &a,const pii &b){return a.second<b.second;});
	multiset<int> se;
	int r=0;
	for(int i=0;i<n;i++)se.insert(0);
	for(int i=0;i<m;i++){
		//部屋iの(出)時刻がdata[i]の入時刻より早い中で最大
		auto it=se.lower_bound(data[i].first);
		if(it!=se.begin()){
			--it;
			se.erase(it);
			se.insert(data[i].second);
			r++;
		}
	}
	printf("%d\n",r);
}

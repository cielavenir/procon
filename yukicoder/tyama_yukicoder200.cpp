#include <deque>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int N,A,B;
	scanf("%d%d",&N,&A);
	deque<int>aa(A);
	for(int i=0;i<A;i++)scanf("%d",&aa[i]);
	sort(aa.begin(),aa.end());
	scanf("%d",&B);
	deque<int>bb(B);
	for(int i=0;i<B;i++)scanf("%d",&bb[i]);
	sort(bb.begin(),bb.end());

	int R=0;
	deque<int>a,b;
	for(;N--;){
		if(a.empty())a=aa;
		if(b.empty())b=bb;
		if(a[a.size()-1]>b[0]){
			R++;
			auto ita=upper_bound(a.begin(),a.end(),b[0]);
			auto itb=lower_bound(b.begin(),b.end(),*ita);
			--itb;
			a.erase(ita);
			b.erase(itb);
		}else{
			a.pop_front();
			b.pop_back();
		}
	}
	printf("%d\n",R);
}
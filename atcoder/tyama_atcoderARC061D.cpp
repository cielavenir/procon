#include <vector>
#include <unordered_set>
#include <cstdio>
using namespace std;

namespace std{
	template<typename I>
	class hash<pair<I,I>>{
		public:
		size_t operator()(pair<I,I> const &p) const {return hash<long long>() (((long long)(p.first))<<32|p.second);}
	};
}

int main(){
	long long H,W;
	int N;
	scanf("%lld%lld%d",&H,&W,&N);
	vector<long long>v(10);
	unordered_set<pair<int,int>>points;
	v[0]=(H-2)*(W-2);
	for(;N--;){
		int h,w;
		scanf("%d%d",&h,&w);h--,w--;
		points.emplace(h,w);
		for(int h0=-1;h0<2;h0++)for(int w0=-1;w0<2;w0++){
			if(1<=h+h0&&h+h0<H-1 && 1<=w+w0&&w+w0<W-1){
				int t=0;
				for(int h1=-1;h1<2;h1++)for(int w1=-1;w1<2;w1++){
					t+=points.find({h+h0+h1,w+w0+w1})!=points.end();
				}
				v[t-1]--;
				v[t]++;
			}
		}
	}
	for(auto &e:v)printf("%lld\n",e);
}
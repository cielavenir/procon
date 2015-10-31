#include <unordered_map>
#include <deque>
#include <numeric>
#include <cstdio>
using namespace std;

int main(){
	unordered_map<int,int>memo;
	int N,c,x;
	for(scanf("%d",&N);~scanf("%d",&N);){
		if(memo.find(N)!=memo.end()){
			printf("%d\n",memo[N]);
			continue;
		}
		deque<int>v(N-N%2);
		iota(v.begin(),v.end(),1+N%2);
		c=0;
		for(;v.size()>2;){ //v is even
			int x=(c+v.size()/2)%v.size();
			v.erase(v.begin()+x);
			if(x<=c)c--;
			c=(c+1)%v.size();
			v.erase(v.begin()+c);
			c--;
			c=(c+1)%v.size();
		}
		printf("%d\n",memo[N]=v[c]);
	}
}
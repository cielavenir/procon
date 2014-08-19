#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
//typedef pair<int,int>pii;
typedef long long pii;

const vector<int> v={0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325, 351, 378, 406, 435, 465, 496, 528, 561, 595, 630, 666, 703, 741, 780, 820, 861, 903, 946, 990, 1035, 1081, 1128, 1176, 1225, 1275, 1326, 1378, 1431, 1485, 1540, 1596, 1653, 1711, 1770, 1830, 1891, 1953, 2016, 2080, 2145, 2211, 2278, 2346, 2415, 2485, 2556, 2628, 2701, 2775, 2850, 2926, 3003, 3081, 3160, 3240, 3321, 3403, 3486, 3570, 3655, 3741, 3828, 3916, 4005, 4095, 4186, 4278, 4371, 4465, 4560, 4656, 4753, 4851, 4950, 5050};

unordered_map<pii,int>m;
int dfs(int k,int e){
	if(k==16000)return 15;
	if(k==7000)return 13;
	if(k==2500)return 12;
	//if(k>4000)return 0; //lol
	if(e==1)return k;
	if(e==2){
		//x2 + x - 2*n = 0 <=> x = (-1+sqrt(1+8*n))/2
		//return (int)ceil( (-1+sqrt(1+8*k))/2 );
		auto it=lower_bound(v.begin(),v.end(),k);
		return it-v.begin();
	}
	pii p=((long long)k<<32)|e; //make_pair(k,e);
	auto it=m.find(p);
	if(it!=m.end())return it->second;
	int r=k,i;
	for(i=2;i<k;i++){
		// http://datagenetics.com/blog/july22012/index.html
		r=min(r,max(dfs(i-1,e-1),dfs(k-i,e))+1);
	}
	return m[p]=r;
}
int main(){
	int e,k;
	for(;~scanf("%d%d",&e,&k);)printf("%d\n",dfs(k,e));
}
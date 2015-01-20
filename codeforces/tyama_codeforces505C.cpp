#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;
const int M=30000;
int z[M+1];
int z1[M+2];
typedef int val_t;

#define laycurse

#if defined(laycurse)
typedef unsigned long long ull;
template<class T>
struct ullHash{
  ull *key; T *val; unsigned memory, size, mask;

  void clear(){memset(val,0,size*sizeof(T));}
  void clear(int sz){size=1;while(size<sz)size*=2;mask=size-1;clear();}
  void init(int mem, int sz){memory=mem;size=1;while(size<sz)size*=2;mask=size-1;if(memory<size)memory=size;key=(ull*)malloc(memory*sizeof(ull));val=(T*)malloc(memory*sizeof(T));if(size)clear();}
  int function(ull a){return (a*97531)&mask;}
  T get(ull a){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;if(key[i]!=a) return -1;return val[i];}
  T set(ull a, T v){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;key[i]=a;val[i]=v;return v;}
  T increase(ull a, T v = 1){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;key[i]=a;return val[i]+=v;}
};
ullHash<int> _hash;
#else
unordered_map<val_t,int>memo;
#endif

int dfs(int cur, int l){
	int ret=0;
	if(cur>M)return 0;
	val_t p=l+cur*(M+1);
#if defined(laycurse)
	if(_hash.get(p)>=0)return _hash.get(p);
#else
	if(memo.find(p)!=memo.end())return memo[p];
#endif
	if(l<=2){
		//for(int i=cur+1;i<=M;i++)ret+=z[i];
		ret=z1[cur+1];
	}else{
		for(int i=-1;i<=1;i++){
			if(0<l+i){
				ret=max(ret,dfs(cur+l+i,l+i));
			}
		}
	}
#if defined(laycurse)
	return _hash.set(p,ret+z[cur]);
#else
	return memo[p]=ret+z[cur];
#endif
}

int main(){
#if defined(laycurse)
	_hash.init(8000000, 8000000);
#else
	memo.reserve(8000000);
#endif
	int N,D;
	cin>>N>>D;
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		z[x]++;
	}
	for(int i=M;i>=0;i--)z1[i]=z[i]+z1[i+1];
	cout<<dfs(D,D)<<endl;
}
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
using namespace std;

int main(){
	vector<int>table(99);
	table[0]=table[1]=1;
	for(int i=2;i<99;i++)if(!table[i])for(int j=i+i;j<99;j+=i)table[j]=1;
	for(int i=2;i<=18;i++){
		vector<int>v(i);
		iota(v.begin(),v.end(),1);
		long long r=0;
		do{
			int j=0;
			for(;j<i;j++)if(table[v[j]+v[(j+1)%i]])break;
			if(j==i)r++;
		}while(next_permutation(v.begin()+1,v.end()));
		printf("%d: %lld\n",i,r);
	}
}
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main(int argc, char **argv){
	freopen(argv[1],"rb",stdin);
	int n,k,i;
	for(;~scanf("%d,%d",&n,&k);){
		vector<int>vec(n);
		for(i=0;i<n;i++)vec[i]=i;
		for(i=0;vec.size()>1;cout<<vec[i]<<' ',vec.erase(vec.begin()+i))if(i+=(k-1)%vec.size(),i>=vec.size())i-=vec.size();
		cout<<vec[0]<<endl;
	}
}
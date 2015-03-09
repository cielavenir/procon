#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	vector<int>v(9);
	for(int i=0;i<9;i++)scanf("%d",&v[i]);
	int ma=0;
	sort(v.begin(),v.end());
	do{
		vector<int>s(3);
		for(int i=0;i<9;i++)s[i/3]+=v[i];
		int mi=min(s[0]/3,min(s[1]/3,s[2]/3));
		if(ma<mi)ma=mi;
	}while(next_permutation(v.begin()+1,v.end()));
	printf("%d\n",ma);
}
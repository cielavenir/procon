#include <vector>
#include <cstdio>
using namespace std;
const vector<int> unit={1,5,10,50,100,500};
int main(){
	int r=0,x;
	for(int i=0;i<unit.size();i++)scanf("%d",&x),r+=unit[i]*x;
	r/=1000;
	printf("%d\n",!!r);
}
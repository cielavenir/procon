#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int N,B;
vector<int>bag;
int main(){
	int i,j,r,m,item;
	scanf("%d%d",&N,&B);
	bag.resize(B+1);bag[0]=1;
	for(i=0;i<N;i++){
		scanf("%d",&item);
		for(j=B;j>=item;j--){
			bag[j]+=bag[j-item];
		}
	}
	puts(bag[B]?"YES":"NO");
}
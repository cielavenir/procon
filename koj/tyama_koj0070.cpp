#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int N,W,i,j,r,m;
	scanf("%d%d",&N,&W);
	vector<pair<int,int> >item(N);//value,weight
	vector<int>bag(N*100+1);
	fill(bag.begin()+1,bag.end(),1<<30);
	for(i=0;i<N;i++)scanf("%d%d",&item[i].second,&item[i].first);
	for(i=0;i<N;i++){
		for(j=bag.size()-1;j>=item[i].first;j--){
			bag[j]=min(bag[j],bag[j-item[i].first]+item[i].second);
		}
	}
	for(int i=bag.size()-1;i>=0;i--){
		if(bag[i]<=W){printf("%d\n",i);break;}
	}
}
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

int N,B;
vector<int>item;
map<int,int>bag;
int main(){
	int i,j,r,m;
	scanf("%d%d",&N,&B);
	item.resize(N);
	bag[0]=1;
	for(i=0;i<N;i++)scanf("%d",&item[i]);
	sort(item.begin(),item.end());
	for(i=0;i<N;i++){
		vector<int>list;
		vector<int>list_n;
		for(map<int,int>::iterator it=bag.begin();it!=bag.end()&&it->first+item[i]<=B;++it){
			list.push_back(it->first);
			list_n.push_back(it->second);
		}
		reverse(list.begin(),list.end());
		reverse(list_n.begin(),list_n.end());
		for(j=0;j<list.size();j++){
			bag[list[j]+item[i]]+=list_n[j];
		}
	}
	printf("%d\n",bag[B]);
}
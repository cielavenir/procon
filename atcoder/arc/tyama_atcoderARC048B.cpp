#include<vector>
#include<unordered_map>
#include<tuple>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	vector<pair<int,int> > ratings(N);
	vector<int> hand(N);
	for(int i=0;i<N;i++){
		int h;
		scanf("%d%d",&ratings[i].first,&h);
		ratings[i].second=i;
		hand[i]=h-1;
	}
	sort(ratings.begin(),ratings.end());
	vector<tuple<int,int,int> >result(N);
	for(int I=0;I<N;){
		int J=distance(ratings.begin(),lower_bound(ratings.begin(),ratings.end(),make_pair(ratings[I].first+1,0)));
		unordered_map<int,int> agg;
		for(int i=I;i<J;i++)agg[hand[ratings[i].second]]++;
		for(int i=I;i<J;i++){
			int h=hand[ratings[i].second];
			result[ratings[i].second]=make_tuple(I+agg[(h+1)%3],N-I-agg[h]-agg[(h+1)%3],agg[h]-1);
		}
		I=J;
	}
	for(int i=0;i<N;i++)printf("%d %d %d\n",get<0>(result[i]),get<1>(result[i]),get<2>(result[i]));
}
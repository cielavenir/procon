#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int dry(vector<int> &v){
	int R=0,lo=0,hi=v.size()-1;
	for(;lo<hi;R++,lo++,hi--){
		for(;lo<hi;hi--)if(v[lo]+v[hi]<0)break;
		if(lo==hi)break;
	}
	return R;
}

int wet(vector<int> &v){
	int R=0,lo=0,hi=v.size()-1;
	for(;lo<hi;R++,lo++,hi--){
		for(;lo<hi;lo++)if(v[lo]+v[hi]>0)break;
		if(lo==hi)break;
	}
	return R;
}

int moist(vector<int> &v){
	int R=0,lo=0,hi=v.size()-1;
	for(;lo<hi;v[lo]+v[hi]==0?R++,hi--:1,lo++){
		for(;lo<hi;hi--)if(v[lo]+v[hi]<=0)break;
		if(lo==hi)break;
	}
	return R;
}

int main(){
	int N;
	scanf("%d",&N);
	vector<int>v(N*=2);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	printf("%d %d %d\n",dry(v),wet(v),moist(v));
}
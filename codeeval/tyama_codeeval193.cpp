//#include "inspect.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool check(string s){
	int i=0,cnt=0;
	for(int j=0;j<s.size();j++)for(int k=j+1;k<s.size();k++)if(s[j]==s[k])return false;
	do{
		i=(i+s[i]-'0')%s.size();
		cnt++;
	}while(i!=0&&cnt<s.size());
	return i==0&&cnt==s.size();
}

int main(){
	char s[9];
	vector<int>v={0,1,2,3,4,5,6,7,8,9,13,15,17,19,31,35,37,39,51,53,57,59,71,73,75,79,91,93,95,97,147,174,258,285,417,471,528,582,714,741,825,852,1263,1267,1623,1627,2316,2356,2396,2631,2635,2639,2671,2675,2679,2716,2756,2796,3126,3162,3526,3562,3926,3962,5263,5267,5623,5627,6231,6235,6239,6271,6275,6279,6312,6352,6392,6712,6752,6792,7126,7162,7526,7562,7926,7962,9263,9267,9623,9627,};

#if 0
	for(int i=0;i<=10000;i++){
		sprintf(s,"%d",i);
		if(check(s)){
			v.push_back(i);
		}
	}
	cout<<v<<endl;
	return 0;
#endif

	int a,b;
	for(;~scanf("%d%d",&a,&b);){
		auto it1=lower_bound(v.begin(),v.end(),a);
		auto it2=upper_bound(v.begin(),v.end(),b);
		if(it1==it2){
			puts("-1");
		}else{
			printf("%d",*it1);
			for(++it1;it1!=it2;++it1)printf(" %d",*it1);
			puts("");
		}
	}
}
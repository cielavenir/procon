#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<pair<int,int>,string> item;
main(){
	int n,i,w,s,S;
	for(string f;cin>>n,n;){
		vector<item>items;
		vector<int>num,result;
		for(i=0;i<n;i++)cin>>f>>w>>s,items.push_back(make_pair(make_pair(w,s),f)),num.push_back(i);
		S=99999;
		do{
			for(s=w=0,i=n-1;~i;i--){
				pair<int,int> weight=items[num[i]].first;
				if(weight.second<w)break;
				w+=weight.first;
				s+=(i+1)*weight.first;
			}
			if(i<0&&s<S)S=s,result=num;
		}while(next_permutation(num.begin(),num.end()));
		for(i=0;i<n;i++)cout<<items[result[i]].second<<endl;
	}
}
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

#define R (f?o:b)

int main(){
	int t=1,T,n,N,r,s;
	for(cin>>T;t<=T;printf("Case #%d: %d\n",t,r),t++){
		vector<pair<string,int> >v;
		for(r=n=0,cin>>N;n<N;n++){
			string s; int x;
			cin>>s>>x;
			v.push_back(make_pair(s,x));
		}
		int o=1,b=1,f=0;
		int c=0,i,j;
		for(;c<v.size();c=i){
			for(i=c+1;i<v.size();i++)
				if(v[c].first!=v[i].first)break;
			//calc time
			for(s=0,j=c;j<i;j++){
				s+=abs(R-v[j].second)+1;
				R=v[j].second;
			}
			r+=s;f^=1;
			if(i<v.size()){
				if(abs(R-v[i].second)<=s)R=v[i].second;
				else if(R<v[i].second)R+=s;
				else R-=s;
			}
		}
	}
}
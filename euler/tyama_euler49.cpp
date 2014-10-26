#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstdio>
#define M 1000000
using namespace std;

char buf[9];
int t[M];
unordered_map<string,vector<int>>h;
int main(){
	int N,K,a,b;
	scanf("%d%d",&N,&K);
	for(a=2;a<=M;a++)if(!t[a]){
		if(a>=1000){
			sprintf(buf,"%d",a);
			string s=buf;
			sort(s.begin(),s.end());
			h[s].push_back(a);
		}
		for(b=a*2;b<=M;b+=a)t[b]=1;
	}
	vector<vector<int>>r;
	for(auto &it:h){
		if(it.second.size()<K)continue;
		for(int i=0;i<it.second.size()-2;i++){
			if(it.second[i]>=N)break;
			for(int j=i+1;j<it.second.size()-1;j++){
				for(int k=j+1;k<it.second.size();k++){
					if(K==3){
						if(it.second[k]-it.second[j]==it.second[j]-it.second[i]){
							r.push_back({it.second[i],it.second[j],it.second[k]});
						}
					}else{
						for(int l=k+1;l<it.second.size();l++){
							if(it.second[l]-it.second[k]==it.second[k]-it.second[j] && it.second[k]-it.second[j]==it.second[j]-it.second[i])
								r.push_back({it.second[i],it.second[j],it.second[k],it.second[l]});
						}
					}
				}
			}
		}
	}
	sort(r.begin(),r.end());
	for(auto &v:r){
		for(int &e:v)printf("%d",e);
		puts("");
	}
}
// 10000 3
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int n;
	for(;cin>>n,n;){
		vector<string>v(n);
		for(int i=0;i<n;i++){
			string s,t;
			cin>>s;
			t+=s[0];
			for(int j=1;j<s.size();j++)if(strchr("aeiou",s[j-1]))t+=s[j];
			v[i]=t;
		}
		sort(v.begin(),v.end());
		if(unique(v.begin(),v.end())!=v.end()){
			puts("-1");
		}else{
			int r=0;
			for(int i=1;i<n;i++){
				int k=0;
				for(;v[i-1][k]==v[i][k];k++);
				if(r<k+1)r=k+1;
			}
			printf("%d\n",r);
		}
	}
}
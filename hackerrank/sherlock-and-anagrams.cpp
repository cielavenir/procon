#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	int T;
	for(cin>>T;T--;){
		int ret=0;
		string s;
		cin>>s;
		for(int l=1;l<=s.size();l++){
			vector<int>x(26);
			int i=0;
			for(;i<l-1;i++)x[s[i]-'a']++;
			for(;i<s.size();){
				x[s[i]-'a']++;
				vector<int> y(26);
				int j=i-l+2;
				for(int c=0;c<l-1;c++,j++)y[s[j]-'a']++;
				for(;j<s.size();){
					y[s[j]-'a']++;
					if(x==y){
						//cout<<l<<' '<<i<<' '<<j<<endl;
						ret++;
					}
					j++;
					y[s[j-l]-'a']--;
				}
				i++;
				x[s[i-l]-'a']--;
			}
		}
		cout<<ret<<endl;
	}
}
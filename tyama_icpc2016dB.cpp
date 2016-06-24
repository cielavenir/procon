#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main(){
	string s;
	int n;
	for(;cin>>n,n;){
		int i=0,ma=0;
		bool f=false;
		map<string,int>votes;
		votes[""]=0;
		for(;i<n;){
			i++;
			cin>>s;
			if(f)continue;
			votes[s]+=1;
			if(ma<votes[s])ma=votes[s];
			char c;
			if(c=[&]()->char{
				char c_=0;
				for(auto &e:votes){
					if(e.second==ma){
						if(c_)return 0;
						c_=e.first[0];
					}else{
						if(e.second+n-i>=ma)return 0;
					}
				}
				return c_;
			}()){
				cout<<c<<' '<<i<<endl;
				f=true;
			}
		}
		if(!f)cout<<"TIE"<<endl;
	}
}
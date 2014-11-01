#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main(){
	int t=1,T,N,Q;
	string s;
	for(cin>>T;t<=T;t++){
		for(cin>>N,Q=0,getline(cin,s);Q<N;Q++)getline(cin,s);
		int r=0;
		unordered_set<string> st;
		for(cin>>Q,getline(cin,s);Q--;){
			getline(cin,s);
			if(st.find(s)==st.end()){
				if(st.size()==N-1)st.clear(),r++;
				st.insert(s);
			}
		}
		cout<<"Case #"<<t<<": "<<r<<endl;
	}
}
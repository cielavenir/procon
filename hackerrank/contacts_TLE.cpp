#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	deque<string> v;
	for(cin>>N;N--;){
		string s,t;
		cin>>s>>t;
		auto it1=lower_bound(v.begin(),v.end(),t);
		if(s[0]=='a'){
			v.insert(it1,t);
		}else{
			t[t.size()-1]++;
			auto it2=lower_bound(v.begin(),v.end(),t);
			printf("%d\n",it2-it1);
		}
	}
}
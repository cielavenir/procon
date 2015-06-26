#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int N;
	unordered_set<string>se;
	for(cin>>N;N--;){
		string s;
		cin>>s;
		se.insert(s);
	}
	vector<char> x={0,'b','g','m','n','r'},y={'a','a','e','i','u','u'};
	do{
		do{
			string s;
			for(int i=0;i<6;i++){
				if(x[i])s+=x[i];
				s+=y[i];
			}
			if(se.find(s)==se.end()){
				cout<<s<<endl;
				return 0;
			}
		}while(next_permutation(y.begin(),y.end()));
	}while(next_permutation(x.begin(),x.end()));
	cout<<"NO"<<endl;
}
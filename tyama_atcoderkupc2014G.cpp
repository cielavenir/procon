#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
	int N,D,i,a,b;
	string s,a1,a2,a3,b1,b2,b3;
	cin>>N>>D;
	for(i=0;i<N;i++){
		if(i/D%3==0)s+='0';
		if(i/D%3==1)s+='1';
		if(i/D%3==2)s+='0'+i%D%2;
	}
	cout<<s<<endl<<flush;
	set<string> dict;
	for(i=0;i<=N-D-3;i++)dict.insert(s.substr(i,3)+s.substr(i+D,3));
	//for(auto it=dict.begin();it!=dict.end();it++)cout<<*it<<endl;
	cin>>a1>>b1;
	cout<<"Move(A,1)"<<endl<<flush;
	cin>>a2>>i;
	cout<<"Move(A,1)"<<endl<<flush;
	cin>>a3>>i;
	cout<<"Move(B,1)"<<endl<<flush;
	cin>>i>>b2;
	cout<<"Move(B,1)"<<endl<<flush;
	cin>>i>>b3;
	cout<<(dict.find(a1+a2+a3+b1+b2+b3)!=dict.end()?"i<j":"i>j")<<endl;
}
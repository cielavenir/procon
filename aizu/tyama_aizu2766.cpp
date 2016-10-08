#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	int N,D;
	string X;
	cin>>N>>X>>D;
	vector<bool>v(N);
	for(int i=0;i<N&&D;i++){
		if(X[i]=='0'){
			v[i]=true;
			X[i]='1';
			D--;
		}
	}
	for(int i=N-1;i>=0&&D;i--){
		if(!v[i]){
			X[i]='0';
			D--;
		}
	}
	cout<<X<<endl;
}

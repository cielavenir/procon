#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	vector<string>v(2);
	cin>>v[0]>>v[1];
	for(int i=0;i<2;i++){
		int cur=i,z=0;
		vector<int>idx(2);
		for(;z<v[0].size();z++,cur^=1){
			for(;idx[cur]<v[cur].size()&&v[cur][idx[cur]]!=v[0][z];idx[cur]++);
			if(v[cur][idx[cur]]!=v[0][z])break;
			idx[cur]++;
		}
		if(z==v[0].size()){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}
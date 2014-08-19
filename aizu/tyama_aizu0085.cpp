#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,k,i;
	for(;cin>>n>>k,n;){
		vector<int>vec(n);
		for(i=0;i<n;i++)vec[i]=i+1;
		for(i=0;vec.size()>1;vec.erase(vec.begin()+i))if(i+=(k-1)%vec.size(),i>=vec.size())i-=vec.size();
		cout<<vec[0]<<endl;
	}
}
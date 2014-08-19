#include <vector>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
int main(){
	long long h=0,h0,a;
	int N,M,H,i=0;
	string s;
	vector<long long>v;
	for(cin>>N>>M>>H;i<N;i++){
		cin>>a,v.push_back(a),h+=a;
	}
	for(;M;M--){
		if(v.size()>3000)return 1;
		cin>>s>>a;
		if(s=="add")v.push_back(a),h+=a;
		else{
			int l=v.size();
			assert(l||h==0);
			if(h<=a-H)
				{cout<<"miss"<<endl;goto done;}
			else if(h-v[l-1]<=a-H)
				{cout<<"go"<<endl,h-=v[l-1],v.pop_back();goto done;}
			else for(h0=i=0;i<l-1;h0+=v[i],i++)if(h0<=a-H&&a+H<=h0+v[i])
				{cout<<"go"<<endl,h-=v[i],v.erase(v.begin()+i);goto done;}
			cout<<"stop"<<endl;
			done:;
		}
	}
}
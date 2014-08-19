#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define M 49
using namespace std;
main(){
	int T,n,i,j,r,c;
	for(cin>>T;T--;){
		cin>>n;
		vector<string>v(n);
		for(i=0;i<n;i++)cin>>v[i];
		for(r=c=0;r<M&&v.size()>1;r++,c=(c+1)%v.size()){
			v[c]+=v[(c+1)%v.size()][0];
			v[(c+1)%v.size()]=v[(c+1)%v.size()].substr(1);
			if(v[(c+1)%v.size()].size()==0){
				v.erase(v.begin()+((c+1)%v.size()));
				if(c==v.size())c--;
			}
			for(j=0;j<v[c].size()-1;j++){
				if(v[c][j]==v[c][v[c].size()-1]){
					v[c]=v[c].substr(0,j)+v[c].substr(j+1,v[c].size()-2-j);
					if(v[c].size()==0)v.erase(v.begin()+c--);
					break;
				}
			}
#if 0
			for(j=0;j<v.size();j++)cout<<(j==c?"[+] ":"[*] ")<<v[j]<<endl;
			cout<<"---"<<endl;
#endif
		}
		cout<<(r==M ? -1 : r)<<endl;
	}
}
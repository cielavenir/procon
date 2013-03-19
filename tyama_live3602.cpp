#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
main(){
	char c;
	int T,m,M,n,i,j,d;
	string s;
	for(cin>>T;T--;){
		cin>>m>>n;
		vector<string>v(m);
		for(i=0;i<m;i++)cin>>v[i];
		for(d=j=0;j<n;j++){
			map<char,int>z;
			for(M=i=0;i<m;i++){
				z[v[i][j]]++;
				if(z[v[i][j]]>M||(z[v[i][j]]==M&&c>v[i][j]))M=z[v[i][j]],c=v[i][j];
			}
			cout<<c;
			d+=m-M;
		}
		cout<<endl;
		cout<<d<<endl;
	}
}
#include <iostream>
#include <string>
using namespace std;
main(){
	int i,j,k,l;
	string line;
	for(;getline(cin,line);){
		int m=0;
		string s;
		for(i=0;i<line.size()-1;i++){
			string b=line.substr(i);
			for(j=1;j<=b.size()/2;j++){
				string t=b.substr(0,j);
				for(l=0,k=1;k+j<=b.size();k++){
					if(b.substr(k,j)==t)l++;
				}
				if(l>0&&m<(l+1)*j)m=(l+1)*j,s=t;
			}
		}
		cout<<(s.size()&&s!=" "?s:"NONE")<<endl;
	}
}
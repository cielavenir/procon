#include <iostream>
#include <string>
using namespace std;
main(){
	string s;
	int m=0,m_idx,k=0,i=0;
	for(cin>>s;i<s.size();i++){
		if(s[i]=='C'){
			if(m>--k)m=k,m_idx=i;
		}
		if(s[i]=='G')k++;
	}
	cout<<(m_idx+1)<<endl;
}
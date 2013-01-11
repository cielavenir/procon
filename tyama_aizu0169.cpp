#include <iostream>
#include <sstream>
using namespace std;
main(){
	int a,r,x;
	string s;
	for(;getline(cin,s);cout<<(r>21?0:a&&r<12?r+10:r)<<endl){
		istringstream is(s);
		for(a=r=0;is>>x;r+=x>9?10:x)if(x==1)a=1;else if(!x)return 0;
	}
}
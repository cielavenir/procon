#include <iostream>
#include <string>
#include <cctype>
using namespace std;
main(){
	string s="*mscvvowyflrtoPltotzvrtbkaojiieqssxhjSrgzraojlayvrogzzivfvsHrghsrmrpvenvoengprupe",t;
	char a[4];
	int i;
	for(a[0]='a';a[0]<='z';a[0]++)for(a[1]='a';a[1]<='z';a[1]++)for(a[2]='a';a[2]<='z';a[2]++)for(a[3]='a';a[3]<='z';a[3]++){
		t=s;
		for(i=0;i<t.size();i++){
			if(islower(t[i]))t[i]=(t[i]-a[i%4]+26)%26+'a';
			else if(isupper(t[i]))t[i]=(t[i]+32-a[i%4]+26)%26+'A';
		}
		if(t.find("means")!=string::npos){
			cout<<t<<endl;
			cout<<a[0]<<a[1]<<a[2]<<a[3]<<endl; // => read
		}
	}
}
/*
answer = twentytwo
* is zeroth block
Pick twentytwo greenboxes
Ordinals have no divisors
Each pair means x and y numn
*/
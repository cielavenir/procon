//tyama_a.cpp
//domestic 2007 A

#include <iostream>
using namespace std;

class foo{
public:
  int icpc(int n){
    int ma=0, mi=1000, sum=0,s;
		for(int i=0;i<n;i++){
			cin >> s;
			ma=max(ma, s);
			mi=min(mi, s);
			sum+=s;
		}
		return (sum-ma-mi)/(n-2);
  }
  
  int main(){
    int n;
	  while(true){
  		cin >> n;
		  if(!n)return 0;
		  cout << icpc(n) << endl;
	  }
    return 0;
  }
};

int main(){return (new foo)->main();}
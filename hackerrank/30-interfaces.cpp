#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class AdvancedArithmetic{
	public:
		virtual int divisorSum(int n)=0;
};

#include <map>
#include <cstring>
class Calculator: public AdvancedArithmetic{
	int divisorSum(int n){
		map<int,int>h;
		char str[32]="factor ";
		sprintf(str+strlen(str),"%d",n);
		FILE *f=popen(str,"r");
		int r;
		for(fscanf(f,"%d:",&r);~fscanf(f,"%d",&r);){
			if(h.find(r)==h.end())h[r]=1;
			h[r]*=r;
		}
		r=1;
		for(auto &e:h)r*=(e.second*e.first-1)/(e.first-1);
		pclose(f);
		return r;
	}
};

int main(){
	int n;
	cin >> n;
	AdvancedArithmetic *myCalculator = new Calculator(); 
	int sum = myCalculator->divisorSum(n);
	cout << "I implemented: AdvancedArithmetic\n" << sum;
	return 0;
}
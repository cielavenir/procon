#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	string line,s;
	for(;getline(cin,line);){
		vector<string> v;
		istringstream ss(line);
		for(;ss>>s;)v.push_back(s);
		sort(v.begin(),v.end());
		for(int i=v.size()-1;i>=0;i--)cout<<v[i]<<(i?' ':'\n');
	}
}
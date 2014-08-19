#include <string>
#include <iostream>
#include <vector>
#include <regex>
using namespace std;

int main(){
	string l,s;
	int n,i,j;
	vector<string> arr,filter;

	getline(cin,l);
	istringstream ss(l);
	for(;ss>>s;)arr.push_back(s);
	cin>>n;
	for(j=0;j<n;j++){
		cin>>s;
		for(i=0;i<s.length();i++)if(s[i]=='*')s[i]='.';
		filter.push_back(s);//string("^")+s+"$");
	}
	for(i=0;i<arr.size();i++){
		for(j=0;j<n;j++)
			if(regex_match(arr[i],regex(filter[j])))break;
		if(j<n)arr[i]=string(arr[i].length(),'*');
	}
	for(i=0;i<arr.size();i++){
		if(i>0)cout<<" ";
		cout<<arr[i];
	}
	cout<<endl;
}